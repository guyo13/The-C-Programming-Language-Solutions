#include <stdio.h>
#define IN 1
#define OUT 0

int is_whitespace_character(int c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int main()
{
    int c;
    int state = 0;

    while ((c = getchar()) != EOF)
    {
        int is_w = is_whitespace_character(c);
        if (is_w)
        {
            if (state == IN)
            {
                putchar('\n');
            }
            state = OUT;
        }
        else
        {
            state = IN;
            putchar(c);
        }
    }
}
