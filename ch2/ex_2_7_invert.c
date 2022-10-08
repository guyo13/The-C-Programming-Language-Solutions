#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#define INT_BITS (int)round(log2((double)UINT_MAX))
#define ALLONES ~0u

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

    // The expression ~(~0u << X) creates a mask where the rightmost X bits are 1 and the rest are 0's
    int y_nbits = (y & ~(ALLONES << n)) << (position - 1);
    int x_low = x & ~(ALLONES << (position - 1));
    // The expression ~(~0u >> X) creates a mask where the leftmost X bits are 1 and the rest are 0's
    int x_high = x & ~(ALLONES >> (INT_BITS - position - n + 1)); // We subtract the first element twice so add 1
    printf("y_nbits %X x_high %X x_low %X\n", y_nbits, x_high, x_low);
    return x_low | y_nbits | x_high;
}

int invert(int x, unsigned int position, unsigned int count)
{
    return setbits(x, position, count, ~x);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s <x> <position> <count>\n", argv[0]);
        return 1;
    }
    printf("Integer size in bits: %d\n", INT_BITS);
    int x = atoi(argv[1]);
    int position = atoi(argv[2]);
    int count = atoi(argv[3]);

    printf("invert(%X, %d, %d)\n", x, position, count);

    int result = invert(x, position, count);
    printf("Result: %X\n", result);
}