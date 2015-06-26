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

#include "parasail.h"


parasail_result_t* parasail_sg_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_table_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_table_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_table_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_table_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_table_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_table_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_table_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_table_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_table_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_table_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_table_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_table_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_table_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_table_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_rowcol_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_rowcol_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_rowcol_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_rowcol_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_rowcol_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_rowcol_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_rowcol_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_rowcol_scan_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_rowcol_scan_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_scan_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_scan_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_rowcol_striped_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_rowcol_striped_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_striped_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_striped_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

parasail_result_t* parasail_sg_stats_rowcol_diag_sat(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t *matrix)
{
    parasail_result_t * result = NULL;
    
    result = parasail_sg_stats_rowcol_diag_8(s1, s1Len, s2, s2Len, open, gap, matrix);
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_diag_16(s1, s1Len, s2, s2Len, open, gap, matrix);
    }
    if (result->saturated) {
        parasail_result_free(result);
        result = parasail_sg_stats_rowcol_diag_32(s1, s1Len, s2, s2Len, open, gap, matrix);
    }

    return result;
}

