/*******************************************************************************
*                                                                              *
*   Configuration header for Mlucas                                            *
*                                                                              *
*******************************************************************************/

#ifndef config_h_included
#define config_h_included

#include <sys/types.h>

/*
 * macOS does not provide memrchr() in its standard library.
 * Define HAVE_MEMRCHR for platforms that do provide it.
 */
#if defined(__linux__)
    /* Linux - memrchr is available (requires _GNU_SOURCE) */
    #define HAVE_MEMRCHR 1
#endif
/* For macOS, Windows, and other platforms, HAVE_MEMRCHR is not defined,
 * indicating that memrchr is not available and our implementation will be used. */

/*
 * Provide memrchr declaration for platforms that don't have it.
 * The implementation is in memrchr.c
 */
#ifndef HAVE_MEMRCHR
void *memrchr(const void *s, int c, size_t n);
#endif

#endif /* config_h_included */
