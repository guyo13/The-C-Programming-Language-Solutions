#include <string.h>
#include <stdio.h>

int any_char(char c, char *s, int s_len);

int any(char *s1, char *s2)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    if (!s1_len || !s2_len)
        return -1;
    // Fence post for optimization (Consecutive chars comparison)
    int current_char = s1[0];
    int is_match = any_char(current_char, s2, s2_len);
    if (is_match)
        return 0;
    int previous_char = current_char;
    for (int i = 1; i < s1_len; i++)
    {
        current_char = s1[i];
        if (current_char != previous_char)
            is_match = any_char(current_char, s2, s2_len);
        if (is_match)
            return i;
        previous_char = current_char;
    }
    return -1;
}

int any_char(char c, char *s, int s_len)
{
    for (int i = 0; i < s_len; i++)
    {
        if (c == s[i])
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <Input string> <Search term>\n", argv[0]);
        return 1;
    }
    int index = any(argv[1], argv[2]);
    printf("Result: %d\n", index);
}