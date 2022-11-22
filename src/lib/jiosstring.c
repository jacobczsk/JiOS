#include "jioslib.h"
int strlen(const char *string)
{
    int strlen = 0;
    while (*string)
    {
        strlen++;
        *string++;
    }
    return strlen;
}