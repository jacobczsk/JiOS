#include "jioslib.h"
void initMem()
{
    bool *memInitialized = (bool *)0xa;
    if (*memInitialized == true)
    {
        return;
    }
    else
    {
        *memInitialized = true;
    }
    int *currentoffset = (int *)0xf;
    *currentoffset = 80;
    int *currentline = (int *)0x1f;
    *currentline = 1;
}