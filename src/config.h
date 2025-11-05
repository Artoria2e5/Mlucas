/*******************************************************************************
*                                                                              *
*   Configuration header for Mlucas                                            *
*                                                                              *
*******************************************************************************/

#ifndef config_h_included
#define config_h_included

/*
 * macOS does not provide memrchr() in its standard library.
 * Define HAVE_MEMRCHR for platforms that do provide it.
 */
#if defined(__APPLE__) && defined(__MACH__)
    /* macOS/Darwin - memrchr is not available */
    #undef HAVE_MEMRCHR
#elif defined(__linux__)
    /* Linux - memrchr is available */
    #define HAVE_MEMRCHR 1
#elif defined(_WIN32) || defined(_WIN64)
    /* Windows - memrchr is not available */
    #undef HAVE_MEMRCHR
#else
    /* For other platforms, assume memrchr is not available by default */
    #undef HAVE_MEMRCHR
#endif

#endif /* config_h_included */
