#include <stdio.h>

int is_whitespace_character(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main()
{
    int c;
    int is_whitespace_seq = 0;

    while ((c = getchar()) != EOF)
    {
        int is_whitespace = is_whitespace_character(c);
        if (is_whitespace)
        {
            is_whitespace_seq = 1;
        }
        else
        {
            printf("Printing sequence:\n");
            if (is_whitespace_seq)
            {
                is_whitespace_seq = 0;
                putchar(' ');
            }
            putchar(c);
        }
    }
}
