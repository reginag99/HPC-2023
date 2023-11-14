/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) Martin Koehler, 2015
 */



#ifndef FLEXIBLAS_CONFIG_H
#define FLEXIBLAS_CONFIG_H

#define FLEXIBLAS_DEFAULT_LIB_PATH "/usr/lib64/flexiblas/"
#define CMAKE_INSTALL_PREFIX "/usr"
#define CMAKE_INSTALL_FULL_LIBDIR "/usr/lib64"
#define CMAKE_INSTALL_FULL_INCLUDEDIR "/usr/include"
#define FLEXIBLAS_LIBRARY_DIR "flexiblas"
#define FLEXIBLAS_LIBRARY_NAME "flexiblas"
#define CMAKE_INSTALL_FULL_SYSCONFDIR "/etc"

/* #undef FLEXIBLAS_FC_I8FLAG */

/* #undef FLEXIBLAS_INTEGER8 */
/* #undef EXTBLAS */
#define HAVE_ATTR_ALIAS
#define HAVE_ATTR_CONSTRUCTOR
#define HAVE_ATTR_HIDDEN
/* #undef HAVE_SYSMACRO_H */
#define HAVE_SYS_STAT_H
/* #undef FALLBACK_NAME */
/* #undef FLEXIBLAS_LAPACK */

#define FLEXIBLAS_LAPACK_3_11_0
/* #undef FLEXIBLAS_LAPACK_3_11_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_10_1 */
/* #undef FLEXIBLAS_LAPACK_3_10_1_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_10_0 */
/* #undef FLEXIBLAS_LAPACK_3_10_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_9_1 */
/* #undef FLEXIBLAS_LAPACK_3_9_1_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_9_0 */
/* #undef FLEXIBLAS_LAPACK_3_9_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_8_0 */
/* #undef FLEXIBLAS_LAPACK_3_8_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_7_0 */
/* #undef FLEXIBLAS_LAPACK_3_7_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_6_1 */
/* #undef FLEXIBLAS_LAPACK_3_6_1_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_6_0 */
/* #undef FLEXIBLAS_LAPACK_3_6_0_WODPRC */
/* #undef FLEXIBLAS_LAPACK_3_5_0 */
/* #undef FLEXIBLAS_LAPACK_3_4_2 */
/* #undef FLEXIBLAS_LAPACK_3_4_1 */
/* #undef FLEXIBLAS_LAPACK_3_4_0 */
/* #undef FLEXIBLAS_LAPACK_3_3_1 */
/* #undef FLEXIBLAS_LAPACK_3_3_0 */

#define FLEXIBLAS_VERSION "3.3.1"
#define FLEXIBLAS_VERSION_MAJOR 3
#define FLEXIBLAS_VERSION_MINOR 3
#define FLEXIBLAS_VERSION_PATCH 1
#define FLEXIBLAS_YEARS "2013-2023"

#ifndef FLEXIBLAS_VERSION_MINOR
#define FLEXIBLAS_VERSION_MINOR 0
#endif
#ifndef FLEXIBLAS_VERSION_PATCH
#define FLEXIBLAS_VERSION_PATCH 0
#endif


#define FLEXIBLAS_RC "flexiblasrc"
#define FLEXIBLAS_RC_DIR "flexiblasrc.d"
#define FLEXIBLAS_PREFIX "flexiblas"

/* #undef FLEXIBLAS_ABI_IBM */
/* #undef FLEXIBLAS_ABI_INTEL */
#define FLEXIBLAS_ABI_GNU

#define HAVE_THREAD_LOCAL
#define HAVE__THREAD_LOCAL
#define HAVE_GNU_THREAD_LOCAL

#define HAVE_RTLD_GLOBAL
#define HAVE_RTLD_DEEPBIND
#define HAVE_RTLD_NOW
#define HAVE_RTLD_NODELETE

#define FLEXIBLAS_DEFAULT_BLAS "NETLIB"

#if defined(HAVE_GNU_THREAD_LOCAL)
 #define TLS_STORE __thread
#elif defined(HAVE__THREAD_LOCAL)
 #define TLS_STORE _Thread_local
#elif defined(HAVE_THREAD_LOCAL)
 #define TLS_STORE thread_local
#else
 #define TLS_STORE
 #warning Thread Local Storage not aviable. FlexiBLAS might cause problems in multithreaded applications.
#endif

#ifndef FALLBACK_NAME
 #define FALLBACK_NAME "libflexiblas_netlib"
#endif
#ifndef LAPACK_FALLBACK_NAME
 #define LAPACK_FALLBACK_NAME "libflexiblas_fallback_lapack"
#endif


// Hidden function
#ifdef HAVE_ATTR_HIDDEN
#define HIDDEN __attribute__((visibility ("hidden")))
#else
#define HIDDEN
#endif


#ifdef FLEXIBLAS_INTEGER8
    #define     ENV_FLEXIBLAS "FLEXIBLAS64"
    #define     ENV_FLEXIBLAS_VERBOSE "FLEXIBLAS64_VERBOSE"
    #define     ENV_FLEXIBLAS_COLOR_OUTPUT "FLEXIBLAS64_COLOR_OUTPUT"
    #define     ENV_FLEXIBLAS_HOOK "FLEXIBLAS64_HOOK"
    #define     ENV_FLEXIBLAS_LIBRARY_PATH "FLEXIBLAS64_LIBRARY_PATH"
    #define     ENV_FLEXIBLAS_NOLAPACK "FLEXIBLAS64_NOLAPACK"
#else
    #define     ENV_FLEXIBLAS "FLEXIBLAS"
    #define     ENV_FLEXIBLAS_VERBOSE "FLEXIBLAS_VERBOSE"
    #define     ENV_FLEXIBLAS_COLOR_OUTPUT "FLEXIBLAS_COLOR_OUTPUT"
    #define     ENV_FLEXIBLAS_HOOK "FLEXIBLAS_HOOK"
    #define     ENV_FLEXIBLAS_LIBRARY_PATH "FLEXIBLAS_LIBRARY_PATH"
    #define     ENV_FLEXIBLAS_NOLAPACK "FLEXIBLAS_NOLAPACK"
#endif

#endif   // Include guard
