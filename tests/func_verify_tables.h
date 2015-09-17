/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#ifndef _PARASAIL_FUNCTION_GROUP_TABLE_H_
#define _PARASAIL_FUNCTION_GROUP_TABLE_H_

#include "parasail.h"

typedef struct parasail_function_group {
    const char * name;
    parasail_function_info_t *fs;
} parasail_function_group_t;

#if HAVE_SSE2
static parasail_function_info_t parasail_nw_table_sse2_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_64,  "parasail_nw_table_scan_sse2_128_64",  "nw",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_32,  "parasail_nw_table_scan_sse2_128_32",  "nw",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_16,  "parasail_nw_table_scan_sse2_128_16",  "nw",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_8,   "parasail_nw_table_scan_sse2_128_8",   "nw",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_64, "parasail_nw_table_striped_sse2_128_64", "nw", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_32, "parasail_nw_table_striped_sse2_128_32", "nw", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_16, "parasail_nw_table_striped_sse2_128_16", "nw", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_8, "parasail_nw_table_striped_sse2_128_8", "nw", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_64,  "parasail_nw_table_diag_sse2_128_64",  "nw",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_32,  "parasail_nw_table_diag_sse2_128_32",  "nw",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_16,  "parasail_nw_table_diag_sse2_128_16",  "nw",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_8,   "parasail_nw_table_diag_sse2_128_8",   "nw",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_sse2 = {"parasail_nw_table_sse2", parasail_nw_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_table_sse41_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_64, "parasail_nw_table_scan_sse41_128_64", "nw",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_32, "parasail_nw_table_scan_sse41_128_32", "nw",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_16, "parasail_nw_table_scan_sse41_128_16", "nw",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_8,  "parasail_nw_table_scan_sse41_128_8",  "nw",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_64, "parasail_nw_table_striped_sse41_128_64", "nw", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_32, "parasail_nw_table_striped_sse41_128_32", "nw", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_16, "parasail_nw_table_striped_sse41_128_16", "nw", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_8, "parasail_nw_table_striped_sse41_128_8", "nw", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_64, "parasail_nw_table_diag_sse41_128_64", "nw",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_32, "parasail_nw_table_diag_sse41_128_32", "nw",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_16, "parasail_nw_table_diag_sse41_128_16", "nw",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_8,  "parasail_nw_table_diag_sse41_128_8",  "nw",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_sse41 = {"parasail_nw_table_sse41", parasail_nw_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_table_avx2_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_64,  "parasail_nw_table_scan_avx2_256_64",  "nw",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_32,  "parasail_nw_table_scan_avx2_256_32",  "nw",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_16,  "parasail_nw_table_scan_avx2_256_16",  "nw",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_8,   "parasail_nw_table_scan_avx2_256_8",   "nw",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_64, "parasail_nw_table_striped_avx2_256_64", "nw", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_32, "parasail_nw_table_striped_avx2_256_32", "nw", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_16, "parasail_nw_table_striped_avx2_256_16", "nw", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_8, "parasail_nw_table_striped_avx2_256_8", "nw", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_64,  "parasail_nw_table_diag_avx2_256_64",  "nw",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_32,  "parasail_nw_table_diag_avx2_256_32",  "nw",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_16,  "parasail_nw_table_diag_avx2_256_16",  "nw",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_8,   "parasail_nw_table_diag_avx2_256_8",   "nw",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_avx2 = {"parasail_nw_table_avx2", parasail_nw_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_nw_table_knc_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_knc_512_32,   "parasail_nw_table_scan_knc_512_32",   "nw",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_knc_512_32, "parasail_nw_table_striped_knc_512_32", "nw", "striped", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_knc_512_32,   "parasail_nw_table_diag_knc_512_32",   "nw",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_knc = {"parasail_nw_table_knc", parasail_nw_table_knc_functions};
#endif
static parasail_function_info_t parasail_nw_table_disp_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_64,           "parasail_nw_table_scan_64",           "nw",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_32,           "parasail_nw_table_scan_32",           "nw",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_16,           "parasail_nw_table_scan_16",           "nw",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_8,            "parasail_nw_table_scan_8",            "nw",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_64,        "parasail_nw_table_striped_64",        "nw", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_32,        "parasail_nw_table_striped_32",        "nw", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_16,        "parasail_nw_table_striped_16",        "nw", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_8,         "parasail_nw_table_striped_8",         "nw", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_64,           "parasail_nw_table_diag_64",           "nw",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_32,           "parasail_nw_table_diag_32",           "nw",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_16,           "parasail_nw_table_diag_16",           "nw",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_8,            "parasail_nw_table_diag_8",            "nw",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sat,          "parasail_nw_table_scan_sat",          "nw",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sat,       "parasail_nw_table_striped_sat",       "nw", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sat,          "parasail_nw_table_diag_sat",          "nw",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_disp = {"parasail_nw_table_disp", parasail_nw_table_disp_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_table_sse2_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_64,  "parasail_sg_table_scan_sse2_128_64",  "sg",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_32,  "parasail_sg_table_scan_sse2_128_32",  "sg",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_16,  "parasail_sg_table_scan_sse2_128_16",  "sg",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_8,   "parasail_sg_table_scan_sse2_128_8",   "sg",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_64, "parasail_sg_table_striped_sse2_128_64", "sg", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_32, "parasail_sg_table_striped_sse2_128_32", "sg", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_16, "parasail_sg_table_striped_sse2_128_16", "sg", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_8, "parasail_sg_table_striped_sse2_128_8", "sg", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_64,  "parasail_sg_table_diag_sse2_128_64",  "sg",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_32,  "parasail_sg_table_diag_sse2_128_32",  "sg",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_16,  "parasail_sg_table_diag_sse2_128_16",  "sg",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_8,   "parasail_sg_table_diag_sse2_128_8",   "sg",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_sse2 = {"parasail_sg_table_sse2", parasail_sg_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_table_sse41_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_64, "parasail_sg_table_scan_sse41_128_64", "sg",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_32, "parasail_sg_table_scan_sse41_128_32", "sg",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_16, "parasail_sg_table_scan_sse41_128_16", "sg",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_8,  "parasail_sg_table_scan_sse41_128_8",  "sg",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_64, "parasail_sg_table_striped_sse41_128_64", "sg", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_32, "parasail_sg_table_striped_sse41_128_32", "sg", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_16, "parasail_sg_table_striped_sse41_128_16", "sg", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_8, "parasail_sg_table_striped_sse41_128_8", "sg", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_64, "parasail_sg_table_diag_sse41_128_64", "sg",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_32, "parasail_sg_table_diag_sse41_128_32", "sg",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_16, "parasail_sg_table_diag_sse41_128_16", "sg",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_8,  "parasail_sg_table_diag_sse41_128_8",  "sg",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_sse41 = {"parasail_sg_table_sse41", parasail_sg_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_table_avx2_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_64,  "parasail_sg_table_scan_avx2_256_64",  "sg",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_32,  "parasail_sg_table_scan_avx2_256_32",  "sg",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_16,  "parasail_sg_table_scan_avx2_256_16",  "sg",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_8,   "parasail_sg_table_scan_avx2_256_8",   "sg",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_64, "parasail_sg_table_striped_avx2_256_64", "sg", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_32, "parasail_sg_table_striped_avx2_256_32", "sg", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_16, "parasail_sg_table_striped_avx2_256_16", "sg", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_8, "parasail_sg_table_striped_avx2_256_8", "sg", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_64,  "parasail_sg_table_diag_avx2_256_64",  "sg",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_32,  "parasail_sg_table_diag_avx2_256_32",  "sg",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_16,  "parasail_sg_table_diag_avx2_256_16",  "sg",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_8,   "parasail_sg_table_diag_avx2_256_8",   "sg",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_avx2 = {"parasail_sg_table_avx2", parasail_sg_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sg_table_knc_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_knc_512_32,   "parasail_sg_table_scan_knc_512_32",   "sg",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_knc_512_32, "parasail_sg_table_striped_knc_512_32", "sg", "striped", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_knc_512_32,   "parasail_sg_table_diag_knc_512_32",   "sg",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_knc = {"parasail_sg_table_knc", parasail_sg_table_knc_functions};
#endif
static parasail_function_info_t parasail_sg_table_disp_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_64,           "parasail_sg_table_scan_64",           "sg",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_32,           "parasail_sg_table_scan_32",           "sg",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_16,           "parasail_sg_table_scan_16",           "sg",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_8,            "parasail_sg_table_scan_8",            "sg",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_64,        "parasail_sg_table_striped_64",        "sg", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_32,        "parasail_sg_table_striped_32",        "sg", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_16,        "parasail_sg_table_striped_16",        "sg", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_8,         "parasail_sg_table_striped_8",         "sg", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_64,           "parasail_sg_table_diag_64",           "sg",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_32,           "parasail_sg_table_diag_32",           "sg",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_16,           "parasail_sg_table_diag_16",           "sg",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_8,            "parasail_sg_table_diag_8",            "sg",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sat,          "parasail_sg_table_scan_sat",          "sg",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sat,       "parasail_sg_table_striped_sat",       "sg", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sat,          "parasail_sg_table_diag_sat",          "sg",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_disp = {"parasail_sg_table_disp", parasail_sg_table_disp_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_table_sse2_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_64,  "parasail_sw_table_scan_sse2_128_64",  "sw",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_32,  "parasail_sw_table_scan_sse2_128_32",  "sw",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_16,  "parasail_sw_table_scan_sse2_128_16",  "sw",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_8,   "parasail_sw_table_scan_sse2_128_8",   "sw",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_64, "parasail_sw_table_striped_sse2_128_64", "sw", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_32, "parasail_sw_table_striped_sse2_128_32", "sw", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_16, "parasail_sw_table_striped_sse2_128_16", "sw", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_8, "parasail_sw_table_striped_sse2_128_8", "sw", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_64,  "parasail_sw_table_diag_sse2_128_64",  "sw",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_32,  "parasail_sw_table_diag_sse2_128_32",  "sw",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_16,  "parasail_sw_table_diag_sse2_128_16",  "sw",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_8,   "parasail_sw_table_diag_sse2_128_8",   "sw",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_sse2 = {"parasail_sw_table_sse2", parasail_sw_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_table_sse41_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_64, "parasail_sw_table_scan_sse41_128_64", "sw",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_32, "parasail_sw_table_scan_sse41_128_32", "sw",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_16, "parasail_sw_table_scan_sse41_128_16", "sw",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_8,  "parasail_sw_table_scan_sse41_128_8",  "sw",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_64, "parasail_sw_table_striped_sse41_128_64", "sw", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_32, "parasail_sw_table_striped_sse41_128_32", "sw", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_16, "parasail_sw_table_striped_sse41_128_16", "sw", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_8, "parasail_sw_table_striped_sse41_128_8", "sw", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_64, "parasail_sw_table_diag_sse41_128_64", "sw",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_32, "parasail_sw_table_diag_sse41_128_32", "sw",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_16, "parasail_sw_table_diag_sse41_128_16", "sw",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_8,  "parasail_sw_table_diag_sse41_128_8",  "sw",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_sse41 = {"parasail_sw_table_sse41", parasail_sw_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_table_avx2_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_64,  "parasail_sw_table_scan_avx2_256_64",  "sw",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_32,  "parasail_sw_table_scan_avx2_256_32",  "sw",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_16,  "parasail_sw_table_scan_avx2_256_16",  "sw",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_8,   "parasail_sw_table_scan_avx2_256_8",   "sw",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_64, "parasail_sw_table_striped_avx2_256_64", "sw", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_32, "parasail_sw_table_striped_avx2_256_32", "sw", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_16, "parasail_sw_table_striped_avx2_256_16", "sw", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_8, "parasail_sw_table_striped_avx2_256_8", "sw", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_64,  "parasail_sw_table_diag_avx2_256_64",  "sw",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_32,  "parasail_sw_table_diag_avx2_256_32",  "sw",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_16,  "parasail_sw_table_diag_avx2_256_16",  "sw",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_8,   "parasail_sw_table_diag_avx2_256_8",   "sw",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_avx2 = {"parasail_sw_table_avx2", parasail_sw_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sw_table_knc_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_knc_512_32,   "parasail_sw_table_scan_knc_512_32",   "sw",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_knc_512_32, "parasail_sw_table_striped_knc_512_32", "sw", "striped", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_knc_512_32,   "parasail_sw_table_diag_knc_512_32",   "sw",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_knc = {"parasail_sw_table_knc", parasail_sw_table_knc_functions};
#endif
static parasail_function_info_t parasail_sw_table_disp_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_64,           "parasail_sw_table_scan_64",           "sw",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_32,           "parasail_sw_table_scan_32",           "sw",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_16,           "parasail_sw_table_scan_16",           "sw",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_8,            "parasail_sw_table_scan_8",            "sw",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_64,        "parasail_sw_table_striped_64",        "sw", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_32,        "parasail_sw_table_striped_32",        "sw", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_16,        "parasail_sw_table_striped_16",        "sw", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_8,         "parasail_sw_table_striped_8",         "sw", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_64,           "parasail_sw_table_diag_64",           "sw",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_32,           "parasail_sw_table_diag_32",           "sw",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_16,           "parasail_sw_table_diag_16",           "sw",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_8,            "parasail_sw_table_diag_8",            "sw",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sat,          "parasail_sw_table_scan_sat",          "sw",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sat,       "parasail_sw_table_striped_sat",       "sw", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sat,          "parasail_sw_table_diag_sat",          "sw",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_disp = {"parasail_sw_table_disp", parasail_sw_table_disp_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_nw_stats_table_sse2_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_64, "parasail_nw_stats_table_scan_sse2_128_64", "nw_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_32, "parasail_nw_stats_table_scan_sse2_128_32", "nw_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_16, "parasail_nw_stats_table_scan_sse2_128_16", "nw_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_8, "parasail_nw_stats_table_scan_sse2_128_8", "nw_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_64, "parasail_nw_stats_table_striped_sse2_128_64", "nw_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_32, "parasail_nw_stats_table_striped_sse2_128_32", "nw_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_16, "parasail_nw_stats_table_striped_sse2_128_16", "nw_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_8, "parasail_nw_stats_table_striped_sse2_128_8", "nw_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_64, "parasail_nw_stats_table_diag_sse2_128_64", "nw_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_32, "parasail_nw_stats_table_diag_sse2_128_32", "nw_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_16, "parasail_nw_stats_table_diag_sse2_128_16", "nw_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_8, "parasail_nw_stats_table_diag_sse2_128_8", "nw_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_sse2 = {"parasail_nw_stats_table_sse2", parasail_nw_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_stats_table_sse41_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_64, "parasail_nw_stats_table_scan_sse41_128_64", "nw_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_32, "parasail_nw_stats_table_scan_sse41_128_32", "nw_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_16, "parasail_nw_stats_table_scan_sse41_128_16", "nw_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_8, "parasail_nw_stats_table_scan_sse41_128_8", "nw_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_64, "parasail_nw_stats_table_striped_sse41_128_64", "nw_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_32, "parasail_nw_stats_table_striped_sse41_128_32", "nw_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_16, "parasail_nw_stats_table_striped_sse41_128_16", "nw_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_8, "parasail_nw_stats_table_striped_sse41_128_8", "nw_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_64, "parasail_nw_stats_table_diag_sse41_128_64", "nw_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_32, "parasail_nw_stats_table_diag_sse41_128_32", "nw_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_16, "parasail_nw_stats_table_diag_sse41_128_16", "nw_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_8, "parasail_nw_stats_table_diag_sse41_128_8", "nw_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_sse41 = {"parasail_nw_stats_table_sse41", parasail_nw_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_stats_table_avx2_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_64, "parasail_nw_stats_table_scan_avx2_256_64", "nw_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_32, "parasail_nw_stats_table_scan_avx2_256_32", "nw_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_16, "parasail_nw_stats_table_scan_avx2_256_16", "nw_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_8, "parasail_nw_stats_table_scan_avx2_256_8", "nw_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_64, "parasail_nw_stats_table_striped_avx2_256_64", "nw_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_32, "parasail_nw_stats_table_striped_avx2_256_32", "nw_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_16, "parasail_nw_stats_table_striped_avx2_256_16", "nw_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_8, "parasail_nw_stats_table_striped_avx2_256_8", "nw_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_64, "parasail_nw_stats_table_diag_avx2_256_64", "nw_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_32, "parasail_nw_stats_table_diag_avx2_256_32", "nw_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_16, "parasail_nw_stats_table_diag_avx2_256_16", "nw_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_8, "parasail_nw_stats_table_diag_avx2_256_8", "nw_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_avx2 = {"parasail_nw_stats_table_avx2", parasail_nw_stats_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_nw_stats_table_knc_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_knc_512_32, "parasail_nw_stats_table_scan_knc_512_32", "nw_stats",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_knc_512_32, "parasail_nw_stats_table_striped_knc_512_32", "nw_stats", "striped", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_knc_512_32, "parasail_nw_stats_table_diag_knc_512_32", "nw_stats",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_knc = {"parasail_nw_stats_table_knc", parasail_nw_stats_table_knc_functions};
#endif
static parasail_function_info_t parasail_nw_stats_table_disp_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_64,     "parasail_nw_stats_table_scan_64",     "nw_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_32,     "parasail_nw_stats_table_scan_32",     "nw_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_16,     "parasail_nw_stats_table_scan_16",     "nw_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_8,      "parasail_nw_stats_table_scan_8",      "nw_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_64,  "parasail_nw_stats_table_striped_64",  "nw_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_32,  "parasail_nw_stats_table_striped_32",  "nw_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_16,  "parasail_nw_stats_table_striped_16",  "nw_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_8,   "parasail_nw_stats_table_striped_8",   "nw_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_64,     "parasail_nw_stats_table_diag_64",     "nw_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_32,     "parasail_nw_stats_table_diag_32",     "nw_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_16,     "parasail_nw_stats_table_diag_16",     "nw_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_8,      "parasail_nw_stats_table_diag_8",      "nw_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sat,    "parasail_nw_stats_table_scan_sat",    "nw_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sat, "parasail_nw_stats_table_striped_sat", "nw_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sat,    "parasail_nw_stats_table_diag_sat",    "nw_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_disp = {"parasail_nw_stats_table_disp", parasail_nw_stats_table_disp_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_stats_table_sse2_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_64, "parasail_sg_stats_table_scan_sse2_128_64", "sg_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_32, "parasail_sg_stats_table_scan_sse2_128_32", "sg_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_16, "parasail_sg_stats_table_scan_sse2_128_16", "sg_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_8, "parasail_sg_stats_table_scan_sse2_128_8", "sg_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_64, "parasail_sg_stats_table_striped_sse2_128_64", "sg_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_32, "parasail_sg_stats_table_striped_sse2_128_32", "sg_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_16, "parasail_sg_stats_table_striped_sse2_128_16", "sg_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_8, "parasail_sg_stats_table_striped_sse2_128_8", "sg_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_64, "parasail_sg_stats_table_diag_sse2_128_64", "sg_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_32, "parasail_sg_stats_table_diag_sse2_128_32", "sg_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_16, "parasail_sg_stats_table_diag_sse2_128_16", "sg_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_8, "parasail_sg_stats_table_diag_sse2_128_8", "sg_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_sse2 = {"parasail_sg_stats_table_sse2", parasail_sg_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_stats_table_sse41_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_64, "parasail_sg_stats_table_scan_sse41_128_64", "sg_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_32, "parasail_sg_stats_table_scan_sse41_128_32", "sg_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_16, "parasail_sg_stats_table_scan_sse41_128_16", "sg_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_8, "parasail_sg_stats_table_scan_sse41_128_8", "sg_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_64, "parasail_sg_stats_table_striped_sse41_128_64", "sg_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_32, "parasail_sg_stats_table_striped_sse41_128_32", "sg_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_16, "parasail_sg_stats_table_striped_sse41_128_16", "sg_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_8, "parasail_sg_stats_table_striped_sse41_128_8", "sg_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_64, "parasail_sg_stats_table_diag_sse41_128_64", "sg_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_32, "parasail_sg_stats_table_diag_sse41_128_32", "sg_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_16, "parasail_sg_stats_table_diag_sse41_128_16", "sg_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_8, "parasail_sg_stats_table_diag_sse41_128_8", "sg_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_sse41 = {"parasail_sg_stats_table_sse41", parasail_sg_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_stats_table_avx2_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_64, "parasail_sg_stats_table_scan_avx2_256_64", "sg_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_32, "parasail_sg_stats_table_scan_avx2_256_32", "sg_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_16, "parasail_sg_stats_table_scan_avx2_256_16", "sg_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_8, "parasail_sg_stats_table_scan_avx2_256_8", "sg_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_64, "parasail_sg_stats_table_striped_avx2_256_64", "sg_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_32, "parasail_sg_stats_table_striped_avx2_256_32", "sg_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_16, "parasail_sg_stats_table_striped_avx2_256_16", "sg_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_8, "parasail_sg_stats_table_striped_avx2_256_8", "sg_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_64, "parasail_sg_stats_table_diag_avx2_256_64", "sg_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_32, "parasail_sg_stats_table_diag_avx2_256_32", "sg_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_16, "parasail_sg_stats_table_diag_avx2_256_16", "sg_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_8, "parasail_sg_stats_table_diag_avx2_256_8", "sg_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_avx2 = {"parasail_sg_stats_table_avx2", parasail_sg_stats_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sg_stats_table_knc_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_knc_512_32, "parasail_sg_stats_table_scan_knc_512_32", "sg_stats",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_knc_512_32, "parasail_sg_stats_table_striped_knc_512_32", "sg_stats", "striped", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_knc_512_32, "parasail_sg_stats_table_diag_knc_512_32", "sg_stats",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_knc = {"parasail_sg_stats_table_knc", parasail_sg_stats_table_knc_functions};
#endif
static parasail_function_info_t parasail_sg_stats_table_disp_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_64,     "parasail_sg_stats_table_scan_64",     "sg_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_32,     "parasail_sg_stats_table_scan_32",     "sg_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_16,     "parasail_sg_stats_table_scan_16",     "sg_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_8,      "parasail_sg_stats_table_scan_8",      "sg_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_64,  "parasail_sg_stats_table_striped_64",  "sg_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_32,  "parasail_sg_stats_table_striped_32",  "sg_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_16,  "parasail_sg_stats_table_striped_16",  "sg_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_8,   "parasail_sg_stats_table_striped_8",   "sg_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_64,     "parasail_sg_stats_table_diag_64",     "sg_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_32,     "parasail_sg_stats_table_diag_32",     "sg_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_16,     "parasail_sg_stats_table_diag_16",     "sg_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_8,      "parasail_sg_stats_table_diag_8",      "sg_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sat,    "parasail_sg_stats_table_scan_sat",    "sg_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sat, "parasail_sg_stats_table_striped_sat", "sg_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sat,    "parasail_sg_stats_table_diag_sat",    "sg_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_disp = {"parasail_sg_stats_table_disp", parasail_sg_stats_table_disp_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_stats_table_sse2_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_64, "parasail_sw_stats_table_scan_sse2_128_64", "sw_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_32, "parasail_sw_stats_table_scan_sse2_128_32", "sw_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_16, "parasail_sw_stats_table_scan_sse2_128_16", "sw_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_8, "parasail_sw_stats_table_scan_sse2_128_8", "sw_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_64, "parasail_sw_stats_table_striped_sse2_128_64", "sw_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_32, "parasail_sw_stats_table_striped_sse2_128_32", "sw_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_16, "parasail_sw_stats_table_striped_sse2_128_16", "sw_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_8, "parasail_sw_stats_table_striped_sse2_128_8", "sw_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_64, "parasail_sw_stats_table_diag_sse2_128_64", "sw_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_32, "parasail_sw_stats_table_diag_sse2_128_32", "sw_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_16, "parasail_sw_stats_table_diag_sse2_128_16", "sw_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_8, "parasail_sw_stats_table_diag_sse2_128_8", "sw_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_sse2 = {"parasail_sw_stats_table_sse2", parasail_sw_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_stats_table_sse41_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_64, "parasail_sw_stats_table_scan_sse41_128_64", "sw_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_32, "parasail_sw_stats_table_scan_sse41_128_32", "sw_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_16, "parasail_sw_stats_table_scan_sse41_128_16", "sw_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_8, "parasail_sw_stats_table_scan_sse41_128_8", "sw_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_64, "parasail_sw_stats_table_striped_sse41_128_64", "sw_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_32, "parasail_sw_stats_table_striped_sse41_128_32", "sw_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_16, "parasail_sw_stats_table_striped_sse41_128_16", "sw_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_8, "parasail_sw_stats_table_striped_sse41_128_8", "sw_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_64, "parasail_sw_stats_table_diag_sse41_128_64", "sw_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_32, "parasail_sw_stats_table_diag_sse41_128_32", "sw_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_16, "parasail_sw_stats_table_diag_sse41_128_16", "sw_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_8, "parasail_sw_stats_table_diag_sse41_128_8", "sw_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_sse41 = {"parasail_sw_stats_table_sse41", parasail_sw_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_stats_table_avx2_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_64, "parasail_sw_stats_table_scan_avx2_256_64", "sw_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_32, "parasail_sw_stats_table_scan_avx2_256_32", "sw_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_16, "parasail_sw_stats_table_scan_avx2_256_16", "sw_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_8, "parasail_sw_stats_table_scan_avx2_256_8", "sw_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_64, "parasail_sw_stats_table_striped_avx2_256_64", "sw_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_32, "parasail_sw_stats_table_striped_avx2_256_32", "sw_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_16, "parasail_sw_stats_table_striped_avx2_256_16", "sw_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_8, "parasail_sw_stats_table_striped_avx2_256_8", "sw_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_64, "parasail_sw_stats_table_diag_avx2_256_64", "sw_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_32, "parasail_sw_stats_table_diag_avx2_256_32", "sw_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_16, "parasail_sw_stats_table_diag_avx2_256_16", "sw_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_8, "parasail_sw_stats_table_diag_avx2_256_8", "sw_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_avx2 = {"parasail_sw_stats_table_avx2", parasail_sw_stats_table_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sw_stats_table_knc_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_knc_512_32, "parasail_sw_stats_table_scan_knc_512_32", "sw_stats",    "scan", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_knc_512_32, "parasail_sw_stats_table_striped_knc_512_32", "sw_stats", "striped", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_knc_512_32, "parasail_sw_stats_table_diag_knc_512_32", "sw_stats",    "diag", "knc",   "512", "32", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_knc = {"parasail_sw_stats_table_knc", parasail_sw_stats_table_knc_functions};
#endif
static parasail_function_info_t parasail_sw_stats_table_disp_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_64,     "parasail_sw_stats_table_scan_64",     "sw_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_32,     "parasail_sw_stats_table_scan_32",     "sw_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_16,     "parasail_sw_stats_table_scan_16",     "sw_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_8,      "parasail_sw_stats_table_scan_8",      "sw_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_64,  "parasail_sw_stats_table_striped_64",  "sw_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_32,  "parasail_sw_stats_table_striped_32",  "sw_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_16,  "parasail_sw_stats_table_striped_16",  "sw_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_8,   "parasail_sw_stats_table_striped_8",   "sw_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_64,     "parasail_sw_stats_table_diag_64",     "sw_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_32,     "parasail_sw_stats_table_diag_32",     "sw_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_16,     "parasail_sw_stats_table_diag_16",     "sw_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_8,      "parasail_sw_stats_table_diag_8",      "sw_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sat,    "parasail_sw_stats_table_scan_sat",    "sw_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sat, "parasail_sw_stats_table_striped_sat", "sw_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sat,    "parasail_sw_stats_table_diag_sat",    "sw_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_disp = {"parasail_sw_stats_table_disp", parasail_sw_stats_table_disp_functions};

#endif /* _PARASAIL_FUNCTION_GROUP_TABLE_H_ */

