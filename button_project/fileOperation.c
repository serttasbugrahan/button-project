#include <stdio.h>
#include <stdlib.h>
#include "Multitimer.h"
#include "fileOperation.h"

uint8_t state = 1;

void mod1(MultiTimer* timer, void *userData)
{
    //mod1 durumu
    if ((state - 1) % 4 == 0)
    {
        printf("kisa\n");
    }
    else if ((state - 2) % 4 == 0)
    {
        printf("uzun\n");
    }
    state++;
    MultiTimerStart(timer, 1000, mod1, userData);
}

void mod2(MultiTimer* timer, void *userData)
{
    if ((state - 1) % 8 == 0 || (state - 2) % 8 == 0)
    {
        printf("kisa\n");
    }
    else if ((state - 3) % 8 == 0 || (state - 6) % 8 == 0)
    {
        printf("uzun\n");
    }
    state++;
    MultiTimerStart(timer, 1000, mod2, userData);
}

