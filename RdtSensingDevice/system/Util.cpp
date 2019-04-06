/*
 * Util.cpp
 *
 * Created: 2019-04-06 10:54:59
 *  Author: kong
 */

#include "system/Util.h"

void* operator new(size_t n)
{
    void* const p = malloc(n);
    return p;
}

void operator delete(void* p)
{
    free(p);
}

unsigned int map(
unsigned int x, unsigned int x_min, unsigned int x_max,
unsigned int y_min, unsigned int y_max)
{
    unsigned int y = ((x - x_min) * (y_max - y_max) / (x_max - x_min)) + y_min;
    return y;
}

void byteToString(unsigned char data, char *str)
{
    unsigned int num = data;
    str[0] = 0x30 + (num  / 100);
    str[1] = 0x30 + ((num % 100) / 10);
    str[2] = 0x30 + (num  % 10);
    str[3] = 0;
}

void wordToString(unsigned int data, char *str)
{
    unsigned int  num = data;
    str[0] = 0x30 + (num  / 10000);
    str[1] = 0x30 + ((num % 10000) / 1000);
    str[2] = 0x30 + ((num % 1000) / 100);
    str[3] = 0x30 + ((num % 100) / 10);
    str[4] = 0x30 + (num  % 10);
    str[5] = 0;
}

/* EOF */