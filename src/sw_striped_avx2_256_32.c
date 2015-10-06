/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdint.h>
#include <stdlib.h>

#include <immintrin.h>

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_avx.h"

#define SWAP(A,B) { __m256i* tmp = A; A = B; B = tmp; }
#define SWAP3(A,B,C) { __m256i* tmp = A; A = B; B = C; C = tmp; }

#define NEG_INF (INT32_MIN/(int32_t)(2))

#if HAVE_AVX2_MM256_INSERT_EPI32
#define _mm256_insert_epi32_rpl _mm256_insert_epi32
#else
static inline __m256i _mm256_insert_epi32_rpl(__m256i a, int32_t i, int imm) {
    __m256i_32_t A;
    A.m = a;
    A.v[imm] = i;
    return A.m;
}
#endif

#if HAVE_AVX2_MM256_EXTRACT_EPI32
#define _mm256_extract_epi32_rpl _mm256_extract_epi32
#else
static inline int32_t _mm256_extract_epi32_rpl(__m256i a, int imm) {
    __m256i_32_t A;
    A.m = a;
    return A.v[imm];
}
#endif

#define _mm256_slli_si256_rpl(a,imm) _mm256_alignr_epi8(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,3,0)), 16-imm)

static inline int32_t _mm256_hmax_epi32_rpl(__m256i a) {
    a = _mm256_max_epi32(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,0,0)));
    a = _mm256_max_epi32(a, _mm256_slli_si256(a, 8));
    a = _mm256_max_epi32(a, _mm256_slli_si256(a, 4));
    return _mm256_extract_epi32_rpl(a, 7);
}


#if defined(PARASAIL_TABLE) || defined(PARASAIL_TRACE)
static inline void arr_store(
        int *array,
        __m256i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen)
{
    array[(0*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 0);
    array[(1*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 1);
    array[(2*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 2);
    array[(3*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 3);
    array[(4*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 4);
    array[(5*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 5);
    array[(6*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 6);
    array[(7*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 7);
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        __m256i vH,
        int32_t t,
        int32_t seglen)
{
    col[0*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 0);
    col[1*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 1);
    col[2*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 2);
    col[3*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 3);
    col[4*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 4);
    col[5*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 5);
    col[6*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 6);
    col[7*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 7);
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_table_striped_avx2_256_32
#define PNAME parasail_sw_table_striped_profile_avx2_256_32
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sw_rowcol_striped_avx2_256_32
#define PNAME parasail_sw_rowcol_striped_profile_avx2_256_32
#else
#ifdef PARASAIL_TRACE
#define FNAME parasail_sw_trace_striped_avx2_256_32
#define PNAME parasail_sw_trace_striped_profile_avx2_256_32
#else
#define FNAME parasail_sw_striped_avx2_256_32
#define PNAME parasail_sw_striped_profile_avx2_256_32
#endif
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    parasail_profile_t *profile = parasail_profile_create_avx_256_32(s1, s1Len, matrix);
    parasail_result_t *result = PNAME(profile, s2, s2Len, open, gap);
    parasail_profile_free(profile);
    return result;
}

parasail_result_t* PNAME(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap)
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t k = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    const int s1Len = profile->s1Len;
    const parasail_matrix_t *matrix = profile->matrix;
    const int32_t segWidth = 8; /* number of values in vector unit */
    const int32_t segLen = (s1Len + segWidth - 1) / segWidth;
    __m256i* const restrict vProfile = (__m256i*)profile->profile32.score;
    __m256i* restrict pvHStore = parasail_memalign___m256i(32, segLen);
    __m256i* restrict pvHLoad =  parasail_memalign___m256i(32, segLen);
    __m256i* const restrict pvE = parasail_memalign___m256i(32, segLen);
    __m256i* restrict pvHMax = parasail_memalign___m256i(32, segLen);
    __m256i vGapO = _mm256_set1_epi32(open);
    __m256i vGapE = _mm256_set1_epi32(gap);
    __m256i vZero = _mm256_setzero_si256();
    int32_t score = NEG_INF;
    __m256i vMaxH = vZero;
    __m256i vMaxHUnit = vZero;
    int32_t maxp = INT32_MAX - (int32_t)(matrix->max+1);
    /*int32_t stop = profile->stop == INT32_MAX ?  INT32_MAX : (int32_t)profile->stop;*/
#ifdef PARASAIL_TABLE
    parasail_result_t *result = parasail_result_new_table1(segLen*segWidth, s2Len);
#else
#ifdef PARASAIL_ROWCOL
    parasail_result_t *result = parasail_result_new_rowcol1(segLen*segWidth, s2Len);
    const int32_t offset = (s1Len - 1) % segLen;
    const int32_t position = (segWidth - 1) - (s1Len - 1) / segLen;
#else
#ifdef PARASAIL_TRACE
    __m256i* const restrict pvHT = parasail_memalign___m256i(32, segLen);
    __m256i* const restrict pvET = parasail_memalign___m256i(32, segLen);
    __m256i* const restrict pvEa = parasail_memalign___m256i(32, segLen);
    parasail_result_t *result = parasail_result_new_trace(segLen*segWidth, s2Len);
    __m256i vTZero = _mm256_set1_epi32(PARASAIL_ZERO);
    __m256i vTIns  = _mm256_set1_epi32(PARASAIL_INS);
    __m256i vTDel  = _mm256_set1_epi32(PARASAIL_DEL);
    __m256i vTDiag = _mm256_set1_epi32(PARASAIL_DIAG);
#else
    parasail_result_t *result = parasail_result_new();
#endif
#endif
#endif

    parasail_memset___m256i(pvHStore, vZero, segLen);
    parasail_memset___m256i(pvE, _mm256_set1_epi32(-open), segLen);

#ifdef PARASAIL_TRACE
    parasail_memset___m256i(pvEa, _mm256_set1_epi32(-open), segLen);
    for (i=0; i<segLen; ++i) {
        arr_store(result->trace_ins_table,
                vTDiag, i, segLen, 0, s2Len);
    }
#endif

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        __m256i vEF_opn;
        __m256i vE;
        __m256i vE_ext;
        __m256i vF;
        __m256i vF_ext;
        __m256i vH;
        __m256i vH_dag;
        const __m256i* vP = NULL;

        /* Initialize F value to 0.  Any errors to vH values will be
         * corrected in the Lazy_F loop. */
        vF = _mm256_sub_epi32(vZero,vGapO);

        /* load final segment of pvHStore and shift left by 4 bytes */
        vH = _mm256_load_si256(&pvHStore[segLen - 1]);
        vH = _mm256_slli_si256_rpl(vH, 4);

        /* Correct part of the vProfile */
        vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;

        if (end_ref == j-2) {
            /* Swap in the max buffer. */
            SWAP3(pvHMax,  pvHLoad,  pvHStore)
        }
        else {
            /* Swap the 2 H buffers. */
            SWAP(pvHLoad,  pvHStore)
        }

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            vE = _mm256_load_si256(pvE + i);

            /* Get max from vH, vE and vF. */
            vH_dag = _mm256_add_epi32(vH, _mm256_load_si256(vP + i));
            vH_dag = _mm256_max_epi32(vH_dag, vZero);
            vH = _mm256_max_epi32(vH_dag, vE);
            vH = _mm256_max_epi32(vH, vF);
            /* Save vH values. */
            _mm256_store_si256(pvHStore + i, vH);

#ifdef PARASAIL_TRACE
            {
                __m256i cond_zero = _mm256_cmpeq_epi32(vH, vZero);
                __m256i case1 = _mm256_cmpeq_epi32(vH, vH_dag);
                __m256i case2 = _mm256_cmpeq_epi32(vH, vF);
                __m256i vT = _mm256_blendv_epi8(
                        _mm256_blendv_epi8(vTIns, vTDel, case2),
                        _mm256_blendv_epi8(vTDiag, vTZero, cond_zero),
                        case1);
                _mm256_store_si256(pvHT + i, vT);
                arr_store(result->trace_table, vT, i, segLen, j, s2Len);
            }
#endif
#ifdef PARASAIL_TABLE
            arr_store(result->score_table, vH, i, segLen, j, s2Len);
#endif
            vMaxH = _mm256_max_epi32(vH, vMaxH);
            vEF_opn = _mm256_sub_epi32(vH, vGapO);

            /* Update vE value. */
            vE_ext = _mm256_sub_epi32(vE, vGapE);
            vE = _mm256_max_epi32(vEF_opn, vE_ext);
            _mm256_store_si256(pvE + i, vE);
#ifdef PARASAIL_TRACE
            {
                __m256i vEa = _mm256_load_si256(pvEa + i);
                __m256i vEa_ext = _mm256_sub_epi32(vEa, vGapE);
                vEa = _mm256_max_epi32(vEF_opn, vEa_ext);
                _mm256_store_si256(pvEa + i, vEa);
                if (j+1<s2Len) {
                    __m256i cond = _mm256_cmpgt_epi32(vEF_opn, vEa_ext);
                    __m256i vT = _mm256_blendv_epi8(vTIns, vTDiag, cond);
                    _mm256_store_si256(pvET + i, vT);
                    arr_store(result->trace_ins_table, vT, i, segLen, j+1, s2Len);
                }
            }
#endif

            /* Update vF value. */
            vF_ext = _mm256_sub_epi32(vF, vGapE);
            vF = _mm256_max_epi32(vEF_opn, vF_ext);
#ifdef PARASAIL_TRACE
            {
                __m256i cond = _mm256_cmpgt_epi32(vEF_opn, vF_ext);
                __m256i vT = _mm256_blendv_epi8(vTDel, vTDiag, cond);
                if (i+1<segLen) {
                    arr_store(result->trace_del_table, vT, i+1, segLen, j, s2Len);
                }
            }
#endif

            /* Load the next vH. */
            vH = _mm256_load_si256(pvHLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
#ifdef PARASAIL_TRACE
            __m256i vFa;
            __m256i vFa_ext;
            __m256i vHp = _mm256_load_si256(&pvHLoad[segLen - 1]);
            vHp = _mm256_slli_si256_rpl(vHp, 4);
            vEF_opn = _mm256_slli_si256_rpl(vEF_opn, 4);
            vEF_opn = _mm256_insert_epi32_rpl(vEF_opn, -open, 0);
            vF_ext = _mm256_slli_si256_rpl(vF_ext, 4);
            vF_ext = _mm256_insert_epi32_rpl(vF_ext, NEG_INF, 0);
            vFa_ext = vF_ext;
#endif
            vF = _mm256_slli_si256_rpl(vF, 4);
            vF = _mm256_insert_epi32_rpl(vF, -open, 0);
#ifdef PARASAIL_TRACE
            vFa = vF;
#endif
            for (i=0; i<segLen; ++i) {
                vH = _mm256_load_si256(pvHStore + i);
                vH = _mm256_max_epi32(vH,vF);
                _mm256_store_si256(pvHStore + i, vH);
#ifdef PARASAIL_TRACE
                {
                    __m256i vT;
                    __m256i case1;
                    __m256i case2;
                    __m256i cond;
                    vHp = _mm256_add_epi32(vHp, _mm256_load_si256(vP + i));
                    vHp = _mm256_max_epi32(vHp, vZero);
                    case1 = _mm256_cmpeq_epi32(vH, vHp);
                    case2 = _mm256_cmpeq_epi32(vH, vF);
                    cond = _mm256_andnot_si256(case1,case2);
                    vT = _mm256_load_si256(pvHT + i);
                    vT = _mm256_blendv_epi8(vT, vTDel, cond);
                    _mm256_store_si256(pvHT + i, vT);
                    arr_store(result->trace_table, vT, i, segLen, j, s2Len);
                }
#endif
#ifdef PARASAIL_TABLE
                arr_store(result->score_table, vH, i, segLen, j, s2Len);
#endif
                vMaxH = _mm256_max_epi32(vH, vMaxH);
                /* Update vF value. */
#ifdef PARASAIL_TRACE
                {
                    __m256i cond = _mm256_cmpgt_epi32(vEF_opn, vFa_ext);
                    __m256i vT = _mm256_blendv_epi8(vTDel, vTDiag, cond);
                    arr_store(result->trace_del_table, vT, i, segLen, j, s2Len);
                }
#endif
                vEF_opn = _mm256_sub_epi32(vH, vGapO);
                vF_ext = _mm256_sub_epi32(vF, vGapE);
#ifdef PARASAIL_TRACE
                {
                    __m256i vET = _mm256_load_si256(pvET + i);
                    __m256i vEa = _mm256_load_si256(pvEa + i);
                    __m256i cond = _mm256_cmpgt_epi32(vEF_opn, vEa);
                    vEa = _mm256_max_epi32(vEa, vEF_opn);
                    _mm256_store_si256(pvEa + i, vEa);
                    vET = _mm256_blendv_epi8(vET, vTDiag, cond);
                    if (j+1<s2Len) {
                        arr_store(result->trace_ins_table, vET, i, segLen, j+1, s2Len);
                    }
                }
#endif
                if (! _mm256_movemask_epi8(
                            _mm256_or_si256(
                                _mm256_cmpgt_epi32(vF_ext, vEF_opn),
                                _mm256_cmpeq_epi32(vF_ext, vEF_opn))))
                    goto end;
                /*vF = _mm256_max_epi32(vEF_opn, vF_ext);*/
                vF = vF_ext;
#ifdef PARASAIL_TRACE
                vFa_ext = _mm256_sub_epi32(vFa, vGapE);
                vFa = _mm256_max_epi32(vEF_opn, vFa_ext);
                vHp = _mm256_load_si256(pvHLoad + i);
#endif
            }
        }
end:
        {
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = _mm256_load_si256(pvHStore + offset);
            for (k=0; k<position; ++k) {
                vH = _mm256_slli_si256_rpl(vH, 4);
            }
            result->score_row[j] = (int32_t) _mm256_extract_epi32_rpl (vH, 7);
        }
#endif

        {
            __m256i vCompare = _mm256_cmpgt_epi32(vMaxH, vMaxHUnit);
            if (_mm256_movemask_epi8(vCompare)) {
                score = _mm256_hmax_epi32_rpl(vMaxH);
                /* if score has potential to overflow, abort early */
                if (score > maxp) {
                    result->saturated = 1;
                    break;
                }
                vMaxHUnit = _mm256_set1_epi32(score);
                end_ref = j;
            }
        }

        /*if (score == stop) break;*/
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        __m256i vH = _mm256_load_si256(pvHStore+i);
        arr_store_col(result->score_col, vH, i, segLen);
    }
#endif

    if (score == INT32_MAX) {
        result->saturated = 1;
    }

    if (result->saturated) {
        score = 0;
        end_query = 0;
        end_ref = 0;
    }
    else {
        if (end_ref == j-1) {
            /* end_ref was the last store column */
            SWAP(pvHMax,  pvHStore)
        }
        else if (end_ref == j-2) {
            /* end_ref was the last load column */
            SWAP(pvHMax,  pvHLoad)
        }
        /* Trace the alignment ending position on read. */
        {
            int32_t *t = (int32_t*)pvHMax;
            int32_t column_len = segLen * segWidth;
            end_query = s1Len - 1;
            for (i = 0; i<column_len; ++i, ++t) {
                if (*t == score) {
                    int32_t temp = i / segWidth + i % segWidth * segLen;
                    if (temp < end_query) {
                        end_query = temp;
                    }
                }
            }
        }
    }

    result->score = score;
    result->end_query = end_query;
    result->end_ref = end_ref;

#ifdef PARASAIL_TRACE
    parasail_free(pvEa);
    parasail_free(pvET);
    parasail_free(pvHT);
#endif
    parasail_free(pvHMax);
    parasail_free(pvE);
    parasail_free(pvHLoad);
    parasail_free(pvHStore);

    return result;
}


