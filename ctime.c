#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ctime.h"

struct timeval start;
struct timeval stop;

void sampleStart() {
  gettimeofday(&start, NULL);
}

void sampleStop() {
  gettimeofday(&stop, NULL);
}

void printTime() {
  stop.tv_sec-=start.tv_sec;
  printf("%f \n",(double)((stop.tv_sec*1000000)+stop.tv_usec));
}
