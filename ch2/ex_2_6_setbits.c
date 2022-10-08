#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_BITS (int)sizeof(int) * 8
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
    return x_low | y_nbits | x_high;
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

    printf("setbits(%X, %d, %d, %X)\n", x, position, count, y);

    int result = setbits(x, position, count, y);
    printf("Result: %X\n", result);
}