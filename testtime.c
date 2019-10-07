#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

struct timeval tame;
int tip, tap;

int main () {
    gettimeofday(&tame, NULL);
    printf("gettimeofday() : %d\n", tame);
    tip=time(NULL);
    printf("time()         : %d\n", tip);
    return(0);
}
