#include "jioslib.h"

void print(const char *string, biosColor fg, biosColor bg)
{
    int *currentoffset = (int *)0xf;
    int *currentline = (int *)0x1f;
    while (*string)
    {
        int lineoffset = *currentoffset + (*currentline * 80);
        *(char *)(0xb8000 + lineoffset) = *string;
        *(int *)(0xb8001 + lineoffset) = bg * 16 + fg;
        *currentoffset += 2;
        if (*currentoffset == 80)
        {
            *currentoffset = 0;
            *currentline++;
        }
        *string++;
    }
    return;
}

void setTitle(const char *string, biosColor fg, biosColor bg)
{
    if (strlen(string) > 80)
    {
        return;
    }
    int plus;
    if (strlen(string) % 2 == 0)
    {
        plus = 0;
    }
    else
    {
        plus = 1;
    }
    int currentoffset = 80 - (strlen(string) + plus);
    while (*string)
    {
        *(char *)(0xb8000 + currentoffset) = *string;
        currentoffset += 2;
        *string++;
    }
    int i = 0;
    currentoffset = 0;
    while (i < 80)
    {
        *(char *)(0xb8001 + currentoffset) = bg * 16 + fg;
        currentoffset += 2;
        i++;
    }
}
void printCenter(const char *string, biosColor fg, biosColor bg)
{
    int *currentline = (int *)0x1f;
    if (strlen(string) > 80)
    {
        return;
    }
    int plus;
    if (strlen(string) % 2 == 0)
    {
        plus = 0;
    }
    else
    {
        plus = 1;
    }
    int currentoffset = 80 - (strlen(string) + plus);
    while (*string)
    {
        *(char *)(0xb8000 + currentoffset + (*currentline * 80 * 2)) = *string;
        currentoffset += 2;
        *string++;
    }
    int i = 0;
    currentoffset = 0;
    while (i < 80)
    {
        *(char *)(0xb8001 + currentoffset + (*currentline * 80 * 2)) = bg * 16 + fg;
        currentoffset += 2;
        i++;
    }
}