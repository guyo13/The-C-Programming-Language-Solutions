#include <stdio.h>
#define MAX_LEN 10
#define LF '\n'
#define TERM '\0'

void reverse(char line[], int len)
{
    int mirror_val;
    for (int i = 0; i < len / 2; ++i)
    {
        int mirror_index = len - 1 - i;
        mirror_val = line[mirror_index];
        line[mirror_index] = line[i];
        line[i] = mirror_val;
    }
}

// 'getline' is already defined in stdio.h, wp K&R!
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != LF; ++i)
    {
        s[i] = c;
    }
    if (c == LF)
    {
        s[i] = c;
        ++i;
    }
    /* Explanation why we are never overflowing here:
     * If we got a sequence of at most MAX_LEN-2 non LF characters then at least 1 LF character -
     * then the above loop exits at the LF mark and therefore assigns both LF and \0 to the next 2 indices - so we'll have space.
     *
     * If we got a sequence of exactly MAX_LEN-1 non LF characters, we're stopping short of reading an LF
     * character because of the for loop condition, and therefore the if condition will fail -
     * and the last space in the array will be assigned the \0 value - so we'll have space.
     *
     * In any case, we're returning the "preceived" length of the line - that is - not including the null termination char.
     */
    s[i] = TERM;
    return i;
}

int main()
{
    char line[MAX_LEN];
    int len = 0;

    while ((len = my_getline(line, MAX_LEN)) > 0)
    {

        reverse(line, len);
        printf("* reversed line: %s\n", line);
    }
}