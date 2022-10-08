#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#define INT_BITS (int)round(log2((double)UINT_MAX))

int setbits(int x, unsigned int position, unsigned int count, int y)
{
    if (position == 0)
    {
        position = 1;
    }
    if (position > INT_BITS || count == 0)
        return x;
    int max_count = INT_BITS - position + 1;
    int n = count > max_count ? max_count : count;

    // The expression ~(~0 << X) creates a mask of 1's where the rightmost X bits are 1 and the rest are 0's
    int y_nbits = (y & ~(~0 << n)) << position;
    int x_mask = x & ~(~0 << position);
    return x_mask | y_nbits;
}

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Usage: %s <x> <y> <position> <count>\n", argv[0]);
        return 1;
    }
    printf("Integer size in bits: %d\n", INT_BITS);
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int position = atoi(argv[3]);
    int count = atoi(argv[4]);

    printf("setbits(%d, %d, %d, %d)\n", x, position, count, y);

    int result = setbits(x, position, count, y);
    printf("Result: %d\n", result);
}