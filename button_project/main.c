#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include "Multitimer.h"
#include "ui.h"
#include "fileOperation.h"


MultiTimer timer1;
MultiTimer timer2;
MultiTimer timer3;

//uint8_t state = 1;
uint64_t PlatformTicksGetFunc(void)
{
    struct timespec current_time;
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    return (uint64_t)((current_time.tv_sec * 1000) + (current_time.tv_nsec / 1000000));
}
int main()
{
    int num;
    FILE *fptr;
    selectMode();
    MultiTimerInstall(PlatformTicksGetFunc);
    getMode(&num, &fptr);
   if (num==1)
   {
        printf("secilen mod =%d\n", num);   
        MultiTimerStart(&timer1, 1000, mod1, NULL); 
      while (1) {
        MultiTimerYield();
    } 
    fclose(fptr);    
   }else if (num==2)
   {
        printf("secilen mod =%d\n", num);   
        MultiTimerStart(&timer2, 1000, mod2, NULL);        
    while (1) {
        MultiTimerYield();
    }
   fclose(fptr); 
    }
}
