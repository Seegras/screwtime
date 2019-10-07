#include <stdio.h>
/* #include <stdlib.h>*/
#include <unistd.h>
#include <time.h>
#include <dlfcn.h>

/* 31536000 is a year */
#define SECONDSOFF 31536000

long tv_sec, tv_usec;
int tz_minuteswest, tz_dsttime;

struct timeval {
    long tv_sec;
    long tv_usec;
    } tv;

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
    } tz;
extern void exit (int __status) __THROW __attribute__ ((__noreturn__));


int gettimeofday (struct timeval *tv, struct timezone *tz) {
    void *handle;
    long int tip, (*oldtimer)(char);
    char *error;

#if defined(__i386__)
    handle = dlopen ("/lib/i386-linux-gnu/libc.so.6", RTLD_LAZY);
#elif defined(__x86_64__)
    handle = dlopen ("/lib/x86_64-linux-gnu/libc.so.6", RTLD_LAZY);
#else
# error Unsupported architecture
#endif
    if (!handle) {
	fputs (dlerror (), stderr);
	exit(1);
	}
    oldtimer = dlsym(handle, "time");
    if ((error = dlerror()) != NULL) {
	fprintf (stderr, "%s\n", error);
	}
    tip=(long int)(*oldtimer)((long int)NULL);
    dlclose(handle);
    tv->tv_sec = (tip-SECONDSOFF);
    return(0);
}

time_t time(time_t *t) {
    void *handle;
    long int tip, (*oldtimer)(char);
    char *error;
    
#if defined(__i386__)
    handle = dlopen ("/lib/i386-linux-gnu/libc.so.6", RTLD_LAZY);
#elif defined(__x86_64__)
    handle = dlopen ("/lib/x86_64-linux-gnu/libc.so.6", RTLD_LAZY);
#else
# error Unsupported architecture
#endif
    if (!handle) {
	fputs (dlerror (), stderr);
	exit(1);
	}
    oldtimer = dlsym(handle, "time");
    if ((error = dlerror()) != NULL) {
	fprintf (stderr, "%s\n", error);
	}
    tip=(*oldtimer)((long int)NULL);
    dlclose(handle);
    t = (long int *)(tip-SECONDSOFF);
    return((long int)t);
}
  