#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_BITS ((int)sizeof(int) * 8)
#define ALLONES ~0u

int rightrot(unsigned int x, unsigned int count)
{
    unsigned int real_count = count % INT_BITS;
    unsigned int rot_part = (x & ~(ALLONES << real_count)) << (INT_BITS - real_count);
    return rot_part | (x >> real_count);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <x> <count>\n", argv[0]);
        return 1;
    }
    printf("Integer size in bits: %d\n", INT_BITS);
    int x = atoi(argv[1]);
    int count = atoi(argv[2]);

    printf("rightrot(%X, %d)\n", x, count);

    int result = rightrot(x, count);
    printf("Result: %X\n", result);
}