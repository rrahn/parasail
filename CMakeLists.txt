PROJECT( parasail )

CMAKE_MINIMUM_REQUIRED( VERSION 3.1 )

SET( CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" ${CMAKE_MODULE_PATH} )

OPTION( BUILD_SHARED_LIBS "Build Shared Libraries" OFF )
SET( LIB_TYPE STATIC )
IF( BUILD_SHARED_LIBS )
  SET( LIB_TYPE SHARED )
  # All OBJECT libraries below are later consumed by a shared library so
  # the following is OK. Saves on setting it as a per target property.
  SET( CMAKE_POSITION_INDEPENDENT_CODE ON )
ENDIF( )

INCLUDE( CheckFunctionExists )
INCLUDE( CheckLibraryExists )
INCLUDE( CheckSymbolExists ) 
INCLUDE( CheckCSourceCompiles ) 
INCLUDE( FindOpenMP ) 
INCLUDE( FindSSE2 )
INCLUDE( FindSSE41 )
INCLUDE( FindAVX2 )
INCLUDE( Findxgetbv )

# Check for restrict keyword
FOREACH( ac_kw __restrict __restrict__ _Restrict restrict )
    CHECK_C_SOURCE_COMPILES(
"
typedef int * int_ptr;
int foo (int_ptr ${ac_kw} ip) {
    return ip[0];
}
int main() {
    int s[1];
    int * ${ac_kw} t = s;
    t[0] = 0;
    return foo(t);
}
"
    HAVE_RESTRICT )
    IF( HAVE_RESTRICT )
        SET( ac_cv_c_restrict ${ac_kw} )
        BREAK( )
    ENDIF( )
ENDFOREACH( )
IF( HAVE_RESTRICT )
    SET( restrict ${ac_cv_c_restrict} )
ELSE( )
    SET( restrict " " )
ENDIF( )

# Check for inline keyword
CHECK_C_SOURCE_COMPILES(
"
typedef int foo_t;
static inline foo_t static_foo(){return 0;}
foo_t foo(){return 0;}
int main(int argc, char *argv[]){return 0;}
"
    HAVE_INLINE_NATIVE )
IF( HAVE_INLINE_NATIVE )
ELSE ( )
    FOREACH( ac_kw __inline__ __inline )
        CHECK_C_SOURCE_COMPILES(
"
typedef int foo_t;
static ${ac_kw} foo_t static_foo(){return 0;}
foo_t foo(){return 0;}
int main(int argc, char *argv[]){return 0;}
"
        HAVE_INLINE )
        IF( HAVE_INLINE )
            SET( ac_cv_c_inline ${ac_kw} )
            BREAK( )
        ENDIF( )
    ENDFOREACH( )
    IF( HAVE_INLINE )
        SET( inline ${ac_cv_c_inline} )
    ELSE( )
        SET( inline " " )
    ENDIF( )
ENDIF( )

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_LIST_DIR} )
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_LIST_DIR}/contrib )
INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )

#CHECK_FUNCTION_EXISTS( _aligned_malloc HAVE__ALIGNED_MALLOC )
#CHECK_FUNCTION_EXISTS( posix_memalign HAVE_POSIX_MEMALIGN )
#CHECK_FUNCTION_EXISTS( aligned_alloc HAVE_ALIGNED_ALLOC )
#CHECK_FUNCTION_EXISTS( memalign HAVE_MEMALIGN )
CHECK_SYMBOL_EXISTS( _aligned_malloc malloc.h HAVE__ALIGNED_MALLOC )
CHECK_SYMBOL_EXISTS( posix_memalign stdlib.h HAVE_POSIX_MEMALIGN )
CHECK_SYMBOL_EXISTS( aligned_alloc stdlib.h HAVE_ALIGNED_ALLOC )
CHECK_SYMBOL_EXISTS( memalign malloc.h HAVE_MEMALIGN )
CHECK_FUNCTION_EXISTS( clock_gettime HAVE_CLOCK_GETTIME_NATIVE )
CHECK_LIBRARY_EXISTS( rt clock_gettime "" HAVE_CLOCK_GETTIME_RT )
CHECK_LIBRARY_EXISTS( pthread clock_gettime "" HAVE_CLOCK_GETTIME_PTHREAD )
CHECK_FUNCTION_EXISTS( sqrt HAVE_SQRT_NATIVE )
CHECK_LIBRARY_EXISTS( m sqrt "" HAVE_SQRT_M )

CONFIGURE_FILE( ${CMAKE_CURRENT_LIST_DIR}/cmake/config.h.in ${CMAKE_BINARY_DIR}/config.h )

SET( SRC_CORE
    src/cpuid.c
    src/function_lookup.c
    src/io.c
    src/isastubs.c
    src/matrix_lookup.c
    src/memory.c
    src/time.c
    src/nw_dispatch.c
    src/sg_dispatch.c
    src/sw_dispatch.c
    src/dispatch_profile.c
    src/satcheck.c
)

SET( SRC_NOVEC
    src/nw.c
    src/sg.c
    src/sw.c
    src/nw_banded.c
    src/nw_scan.c
    src/sg_scan.c
    src/sw_scan.c
    src/nw_stats.c
    src/sg_stats.c
    src/sw_stats.c
    src/nw_stats_scan.c
    src/sg_stats_scan.c
    src/sw_stats_scan.c
)

SET( SRC_SSE2
    src/nw_scan_sse2_128_64.c
    src/sg_scan_sse2_128_64.c
    src/sw_scan_sse2_128_64.c
    src/nw_scan_sse2_128_32.c
    src/sg_scan_sse2_128_32.c
    src/sw_scan_sse2_128_32.c
    src/nw_scan_sse2_128_16.c
    src/sg_scan_sse2_128_16.c
    src/sw_scan_sse2_128_16.c
    src/nw_scan_sse2_128_8.c
    src/sg_scan_sse2_128_8.c
    src/sw_scan_sse2_128_8.c
    src/nw_diag_sse2_128_64.c
    src/sg_diag_sse2_128_64.c
    src/sw_diag_sse2_128_64.c
    src/nw_diag_sse2_128_32.c
    src/sg_diag_sse2_128_32.c
    src/sw_diag_sse2_128_32.c
    src/nw_diag_sse2_128_16.c
    src/sg_diag_sse2_128_16.c
    src/sw_diag_sse2_128_16.c
    src/nw_diag_sse2_128_8.c
    src/sg_diag_sse2_128_8.c
    src/sw_diag_sse2_128_8.c
    src/nw_striped_sse2_128_64.c
    src/sg_striped_sse2_128_64.c
    src/sw_striped_sse2_128_64.c
    src/nw_striped_sse2_128_32.c
    src/sg_striped_sse2_128_32.c
    src/sw_striped_sse2_128_32.c
    src/nw_striped_sse2_128_16.c
    src/sg_striped_sse2_128_16.c
    src/sw_striped_sse2_128_16.c
    src/nw_striped_sse2_128_8.c
    src/sg_striped_sse2_128_8.c
    src/sw_striped_sse2_128_8.c
#   src/nw_blocked_sse2_128_32.c
#   src/sg_blocked_sse2_128_32.c
#   src/sw_blocked_sse2_128_32.c
#   src/nw_blocked_sse2_128_16.c
#   src/sg_blocked_sse2_128_16.c
#   src/sw_blocked_sse2_128_16.c
#   src/nw_blocked_sse2_128_8.c
#   src/sg_blocked_sse2_128_8.c
#   src/sw_blocked_sse2_128_8.c
    src/nw_stats_scan_sse2_128_64.c
    src/sg_stats_scan_sse2_128_64.c
    src/sw_stats_scan_sse2_128_64.c
    src/nw_stats_scan_sse2_128_32.c
    src/sg_stats_scan_sse2_128_32.c
    src/sw_stats_scan_sse2_128_32.c
    src/nw_stats_scan_sse2_128_16.c
    src/sg_stats_scan_sse2_128_16.c
    src/sw_stats_scan_sse2_128_16.c
    src/nw_stats_scan_sse2_128_8.c
    src/sg_stats_scan_sse2_128_8.c
    src/sw_stats_scan_sse2_128_8.c
    src/nw_stats_diag_sse2_128_64.c
    src/sg_stats_diag_sse2_128_64.c
    src/sw_stats_diag_sse2_128_64.c
    src/nw_stats_diag_sse2_128_32.c
    src/sg_stats_diag_sse2_128_32.c
    src/sw_stats_diag_sse2_128_32.c
    src/nw_stats_diag_sse2_128_16.c
    src/sg_stats_diag_sse2_128_16.c
    src/sw_stats_diag_sse2_128_16.c
    src/nw_stats_diag_sse2_128_8.c
    src/sg_stats_diag_sse2_128_8.c
    src/sw_stats_diag_sse2_128_8.c
    src/nw_stats_striped_sse2_128_64.c
    src/sg_stats_striped_sse2_128_64.c
    src/sw_stats_striped_sse2_128_64.c
    src/nw_stats_striped_sse2_128_32.c
    src/sg_stats_striped_sse2_128_32.c
    src/sw_stats_striped_sse2_128_32.c
    src/nw_stats_striped_sse2_128_16.c
    src/sg_stats_striped_sse2_128_16.c
    src/sw_stats_striped_sse2_128_16.c
    src/nw_stats_striped_sse2_128_8.c
    src/sg_stats_striped_sse2_128_8.c
    src/sw_stats_striped_sse2_128_8.c
)

SET( SRC_SSE41
    src/nw_scan_sse41_128_64.c
    src/sg_scan_sse41_128_64.c
    src/sw_scan_sse41_128_64.c
    src/nw_scan_sse41_128_32.c
    src/sg_scan_sse41_128_32.c
    src/sw_scan_sse41_128_32.c
    src/nw_scan_sse41_128_16.c
    src/sg_scan_sse41_128_16.c
    src/sw_scan_sse41_128_16.c
    src/nw_scan_sse41_128_8.c
    src/sg_scan_sse41_128_8.c
    src/sw_scan_sse41_128_8.c
    src/nw_diag_sse41_128_64.c
    src/sg_diag_sse41_128_64.c
    src/sw_diag_sse41_128_64.c
    src/nw_diag_sse41_128_32.c
    src/sg_diag_sse41_128_32.c
    src/sw_diag_sse41_128_32.c
    src/nw_diag_sse41_128_16.c
    src/sg_diag_sse41_128_16.c
    src/sw_diag_sse41_128_16.c
    src/nw_diag_sse41_128_8.c
    src/sg_diag_sse41_128_8.c
    src/sw_diag_sse41_128_8.c
    src/nw_striped_sse41_128_64.c
    src/sg_striped_sse41_128_64.c
    src/sw_striped_sse41_128_64.c
    src/nw_striped_sse41_128_32.c
    src/sg_striped_sse41_128_32.c
    src/sw_striped_sse41_128_32.c
    src/nw_striped_sse41_128_16.c
    src/sg_striped_sse41_128_16.c
    src/sw_striped_sse41_128_16.c
    src/nw_striped_sse41_128_8.c
    src/sg_striped_sse41_128_8.c
    src/sw_striped_sse41_128_8.c
#   src/nw_blocked_sse41_128_32.c
#   src/sg_blocked_sse41_128_32.c
    src/sw_blocked_sse41_128_32.c
#   src/nw_blocked_sse41_128_16.c
#   src/sg_blocked_sse41_128_16.c
    src/sw_blocked_sse41_128_16.c
#   src/nw_blocked_sse41_128_8.c
#   src/sg_blocked_sse41_128_8.c
#   src/sw_blocked_sse41_128_8.c
    src/nw_stats_scan_sse41_128_64.c
    src/sg_stats_scan_sse41_128_64.c
    src/sw_stats_scan_sse41_128_64.c
    src/nw_stats_scan_sse41_128_32.c
    src/sg_stats_scan_sse41_128_32.c
    src/sw_stats_scan_sse41_128_32.c
    src/nw_stats_scan_sse41_128_16.c
    src/sg_stats_scan_sse41_128_16.c
    src/sw_stats_scan_sse41_128_16.c
    src/nw_stats_scan_sse41_128_8.c
    src/sg_stats_scan_sse41_128_8.c
    src/sw_stats_scan_sse41_128_8.c
    src/nw_stats_diag_sse41_128_64.c
    src/sg_stats_diag_sse41_128_64.c
    src/sw_stats_diag_sse41_128_64.c
    src/nw_stats_diag_sse41_128_32.c
    src/sg_stats_diag_sse41_128_32.c
    src/sw_stats_diag_sse41_128_32.c
    src/nw_stats_diag_sse41_128_16.c
    src/sg_stats_diag_sse41_128_16.c
    src/sw_stats_diag_sse41_128_16.c
    src/nw_stats_diag_sse41_128_8.c
    src/sg_stats_diag_sse41_128_8.c
    src/sw_stats_diag_sse41_128_8.c
    src/nw_stats_striped_sse41_128_64.c
    src/sg_stats_striped_sse41_128_64.c
    src/sw_stats_striped_sse41_128_64.c
    src/nw_stats_striped_sse41_128_32.c
    src/sg_stats_striped_sse41_128_32.c
    src/sw_stats_striped_sse41_128_32.c
    src/nw_stats_striped_sse41_128_16.c
    src/sg_stats_striped_sse41_128_16.c
    src/sw_stats_striped_sse41_128_16.c
    src/nw_stats_striped_sse41_128_8.c
    src/sg_stats_striped_sse41_128_8.c
    src/sw_stats_striped_sse41_128_8.c
)

SET( SRC_AVX2
    src/nw_scan_avx2_256_64.c
    src/sg_scan_avx2_256_64.c
    src/sw_scan_avx2_256_64.c
    src/nw_scan_avx2_256_32.c
    src/sg_scan_avx2_256_32.c
    src/sw_scan_avx2_256_32.c
    src/nw_scan_avx2_256_16.c
    src/sg_scan_avx2_256_16.c
    src/sw_scan_avx2_256_16.c
    src/nw_scan_avx2_256_8.c
    src/sg_scan_avx2_256_8.c
    src/sw_scan_avx2_256_8.c
    src/nw_diag_avx2_256_64.c
    src/sg_diag_avx2_256_64.c
    src/sw_diag_avx2_256_64.c
    src/nw_diag_avx2_256_32.c
    src/sg_diag_avx2_256_32.c
    src/sw_diag_avx2_256_32.c
    src/nw_diag_avx2_256_16.c
    src/sg_diag_avx2_256_16.c
    src/sw_diag_avx2_256_16.c
    src/nw_diag_avx2_256_8.c
    src/sg_diag_avx2_256_8.c
    src/sw_diag_avx2_256_8.c
    src/nw_striped_avx2_256_64.c
    src/sg_striped_avx2_256_64.c
    src/sw_striped_avx2_256_64.c
    src/nw_striped_avx2_256_32.c
    src/sg_striped_avx2_256_32.c
    src/sw_striped_avx2_256_32.c
    src/nw_striped_avx2_256_16.c
    src/sg_striped_avx2_256_16.c
    src/sw_striped_avx2_256_16.c
    src/nw_striped_avx2_256_8.c
    src/sg_striped_avx2_256_8.c
    src/sw_striped_avx2_256_8.c
#   src/nw_blocked_avx2_256_32.c
#   src/sg_blocked_avx2_256_32.c
#   src/sw_blocked_avx2_256_32.c
#   src/nw_blocked_avx2_256_16.c
#   src/sg_blocked_avx2_256_16.c
#   src/sw_blocked_avx2_256_16.c
#   src/nw_blocked_avx2_256_8.c
#   src/sg_blocked_avx2_256_8.c
#   src/sw_blocked_avx2_256_8.c
    src/nw_stats_scan_avx2_256_64.c
    src/sg_stats_scan_avx2_256_64.c
    src/sw_stats_scan_avx2_256_64.c
    src/nw_stats_scan_avx2_256_32.c
    src/sg_stats_scan_avx2_256_32.c
    src/sw_stats_scan_avx2_256_32.c
    src/nw_stats_scan_avx2_256_16.c
    src/sg_stats_scan_avx2_256_16.c
    src/sw_stats_scan_avx2_256_16.c
    src/nw_stats_scan_avx2_256_8.c
    src/sg_stats_scan_avx2_256_8.c
    src/sw_stats_scan_avx2_256_8.c
    src/nw_stats_diag_avx2_256_64.c
    src/sg_stats_diag_avx2_256_64.c
    src/sw_stats_diag_avx2_256_64.c
    src/nw_stats_diag_avx2_256_32.c
    src/sg_stats_diag_avx2_256_32.c
    src/sw_stats_diag_avx2_256_32.c
    src/nw_stats_diag_avx2_256_16.c
    src/sg_stats_diag_avx2_256_16.c
    src/sw_stats_diag_avx2_256_16.c
    src/nw_stats_diag_avx2_256_8.c
    src/sg_stats_diag_avx2_256_8.c
    src/sw_stats_diag_avx2_256_8.c
    src/nw_stats_striped_avx2_256_64.c
    src/sg_stats_striped_avx2_256_64.c
    src/sw_stats_striped_avx2_256_64.c
    src/nw_stats_striped_avx2_256_32.c
    src/sg_stats_striped_avx2_256_32.c
    src/sw_stats_striped_avx2_256_32.c
    src/nw_stats_striped_avx2_256_16.c
    src/sg_stats_striped_avx2_256_16.c
    src/sw_stats_striped_avx2_256_16.c
    src/nw_stats_striped_avx2_256_8.c
    src/sg_stats_striped_avx2_256_8.c
    src/sw_stats_striped_avx2_256_8.c
)

SET( SRC_KNC
    src/memory_knc.c
    src/nw_scan_knc_512_32.c
    src/sg_scan_knc_512_32.c
    src/sw_scan_knc_512_32.c
    src/nw_diag_knc_512_32.c
    src/sg_diag_knc_512_32.c
    src/sw_diag_knc_512_32.c
    src/nw_striped_knc_512_32.c
    src/sg_striped_knc_512_32.c
    src/sw_striped_knc_512_32.c
#   src/nw_blocked_knc_512_32.c
#   src/sg_blocked_knc_512_32.c
#   src/sw_blocked_knc_512_32.c
    src/nw_stats_scan_knc_512_32.c
    src/sg_stats_scan_knc_512_32.c
    src/sw_stats_scan_knc_512_32.c
    src/nw_stats_diag_knc_512_32.c
    src/sg_stats_diag_knc_512_32.c
    src/sw_stats_diag_knc_512_32.c
    src/nw_stats_striped_knc_512_32.c
    src/sg_stats_striped_knc_512_32.c
    src/sw_stats_striped_knc_512_32.c
)

ADD_LIBRARY( parasail_core OBJECT ${SRC_CORE} )

ADD_LIBRARY( parasail_novec OBJECT ${SRC_NOVEC} )
ADD_LIBRARY( parasail_novec_table OBJECT ${SRC_NOVEC} )
ADD_LIBRARY( parasail_novec_rowcol OBJECT ${SRC_NOVEC} )
SET_TARGET_PROPERTIES( parasail_novec_table PROPERTIES COMPILE_DEFINITIONS PARASAIL_TABLE )
SET_TARGET_PROPERTIES( parasail_novec_rowcol PROPERTIES COMPILE_DEFINITIONS PARASAIL_ROWCOL )

IF( SSE2_FOUND )
    ADD_LIBRARY( parasail_sse2 OBJECT ${SRC_SSE2} src/memory_sse.c )
    ADD_LIBRARY( parasail_sse2_table OBJECT ${SRC_SSE2} )
    ADD_LIBRARY( parasail_sse2_rowcol OBJECT ${SRC_SSE2} )
    SET_TARGET_PROPERTIES( parasail_sse2 PROPERTIES COMPILE_FLAGS ${SSE2_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_sse2_table PROPERTIES COMPILE_FLAGS ${SSE2_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_sse2_rowcol PROPERTIES COMPILE_FLAGS ${SSE2_C_FLAGS} )
ELSE( )
    ADD_LIBRARY( parasail_sse2 OBJECT cmake/sse2_dummy.c )
    ADD_LIBRARY( parasail_sse2_table OBJECT cmake/sse2_dummy.c )
    ADD_LIBRARY( parasail_sse2_rowcol OBJECT cmake/sse2_dummy.c )
ENDIF( )
SET_TARGET_PROPERTIES( parasail_sse2_table PROPERTIES COMPILE_DEFINITIONS PARASAIL_TABLE )
SET_TARGET_PROPERTIES( parasail_sse2_rowcol PROPERTIES COMPILE_DEFINITIONS PARASAIL_ROWCOL )

IF( SSE41_FOUND )
    ADD_LIBRARY( parasail_sse41 OBJECT ${SRC_SSE41} )
    ADD_LIBRARY( parasail_sse41_table OBJECT ${SRC_SSE41} )
    ADD_LIBRARY( parasail_sse41_rowcol OBJECT ${SRC_SSE41} )
    SET_TARGET_PROPERTIES( parasail_sse41 PROPERTIES COMPILE_FLAGS ${SSE41_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_sse41_table PROPERTIES COMPILE_FLAGS ${SSE41_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_sse41_rowcol PROPERTIES COMPILE_FLAGS ${SSE41_C_FLAGS} )
ELSE( )
    ADD_LIBRARY( parasail_sse41 OBJECT cmake/sse41_dummy.c )
    ADD_LIBRARY( parasail_sse41_table OBJECT cmake/sse41_dummy.c )
    ADD_LIBRARY( parasail_sse41_rowcol OBJECT cmake/sse41_dummy.c )
ENDIF( )
SET_TARGET_PROPERTIES( parasail_sse41_table PROPERTIES COMPILE_DEFINITIONS PARASAIL_TABLE )
SET_TARGET_PROPERTIES( parasail_sse41_rowcol PROPERTIES COMPILE_DEFINITIONS PARASAIL_ROWCOL )

IF( AVX2_FOUND )
    ADD_LIBRARY( parasail_avx2 OBJECT ${SRC_AVX2} src/memory_avx2.c )
    ADD_LIBRARY( parasail_avx2_table OBJECT ${SRC_AVX2} )
    ADD_LIBRARY( parasail_avx2_rowcol OBJECT ${SRC_AVX2} )
    SET_TARGET_PROPERTIES( parasail_avx2 PROPERTIES COMPILE_FLAGS ${AVX2_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_avx2_table PROPERTIES COMPILE_FLAGS ${AVX2_C_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_avx2_rowcol PROPERTIES COMPILE_FLAGS ${AVX2_C_FLAGS} )
ELSE( )
    ADD_LIBRARY( parasail_avx2 OBJECT cmake/avx2_dummy.c )
    ADD_LIBRARY( parasail_avx2_table OBJECT cmake/avx2_dummy.c )
    ADD_LIBRARY( parasail_avx2_rowcol OBJECT cmake/avx2_dummy.c )
ENDIF( )
SET_TARGET_PROPERTIES( parasail_avx2_table PROPERTIES COMPILE_DEFINITIONS PARASAIL_TABLE )
SET_TARGET_PROPERTIES( parasail_avx2_rowcol PROPERTIES COMPILE_DEFINITIONS PARASAIL_ROWCOL )

ADD_LIBRARY( sais OBJECT contrib/sais-lite-lcp/sais.c )
TARGET_INCLUDE_DIRECTORIES( sais PRIVATE ${CMAKE_CURRENT_LIST_DIR}/contrib/sais-lite-lcp )

SET( maybe_def )
IF( WIN32 )
    IF( BUILD_SHARED_LIBS )
        LIST( APPEND maybe_def cmake/parasail.def )
    ENDIF( )
ENDIF( )

ADD_LIBRARY( parasail ${LIB_TYPE}
    $<TARGET_OBJECTS:parasail_core>
    $<TARGET_OBJECTS:parasail_novec>
    $<TARGET_OBJECTS:parasail_novec_table>
    $<TARGET_OBJECTS:parasail_novec_rowcol>
    $<TARGET_OBJECTS:parasail_sse2>
    $<TARGET_OBJECTS:parasail_sse2_table>
    $<TARGET_OBJECTS:parasail_sse2_rowcol>
    $<TARGET_OBJECTS:parasail_sse41>
    $<TARGET_OBJECTS:parasail_sse41_table>
    $<TARGET_OBJECTS:parasail_sse41_rowcol>
    $<TARGET_OBJECTS:parasail_avx2>
    $<TARGET_OBJECTS:parasail_avx2_table>
    $<TARGET_OBJECTS:parasail_avx2_rowcol>
    ${maybe_def}
)

TARGET_INCLUDE_DIRECTORIES(parasail PUBLIC ${CMAKE_CURRENT_LIST_DIR})

IF( HAVE_CLOCK_GETTIME_NATIVE )
ELSEIF( HAVE_CLOCK_GETTIME_RT )
    TARGET_LINK_LIBRARIES( parasail rt )
ELSEIF( HAVE_CLOCK_GETTIME_PTHREAD )
    TARGET_LINK_LIBRARIES( parasail pthread )
ENDIF( )
IF( HAVE_SQRT_NATIVE )
ELSEIF( HAVE_SQRT_M )
    TARGET_LINK_LIBRARIES( parasail m )
ENDIF( )

SET( maybe_getopt )
IF( WIN32 )
    LIST( APPEND maybe_getopt contrib/wingetopt/src/getopt.c )
ENDIF( )
ADD_EXECUTABLE( parasail_aligner apps/parasail_aligner.cpp $<TARGET_OBJECTS:sais> ${maybe_getopt} )
IF( OPENMP_FOUND )
    SET_TARGET_PROPERTIES( parasail_aligner PROPERTIES COMPILE_FLAGS ${OpenMP_CXX_FLAGS} )
    SET_TARGET_PROPERTIES( parasail_aligner PROPERTIES LINK_FLAGS ${OpenMP_CXX_FLAGS} )
ENDIF( )
TARGET_LINK_LIBRARIES( parasail_aligner parasail )
TARGET_INCLUDE_DIRECTORIES( parasail_aligner PRIVATE ${CMAKE_CURRENT_LIST_DIR}/contrib/sais-lite-lcp )

ADD_EXECUTABLE( parasail_stats apps/parasail_stats.c )
TARGET_LINK_LIBRARIES( parasail_stats parasail )

ADD_EXECUTABLE( test_isa tests/test_isa.c )
TARGET_LINK_LIBRARIES( test_isa parasail )

ADD_EXECUTABLE( test_matrix tests/test_matrix.c )
TARGET_LINK_LIBRARIES( test_matrix parasail )

INSTALL( FILES parasail.h DESTINATION include )
INSTALL( DIRECTORY parasail DESTINATION include )
INSTALL( TARGETS parasail parasail_aligner parasail_stats
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
