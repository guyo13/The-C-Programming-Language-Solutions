#include <string.h>
#include <stdio.h>
#define TERM '\0'

int any(char c, char *s, int s_len);

/// @brief Deletes all characters from a string that match any characters in another string.
/// @param str - The string to delete from.
/// @param del - The reference character string.
/// @return The new length of the string.
unsigned int squeeze(char *str, char *del)
{
    int len = strlen(str);
    int d_len = strlen(del);
    int pos, previous_char;
    pos = previous_char = 0;
    if (!len)
    {
        return 0;
    }

    // Fence post so we can apply optimization in the following loop - checking current and previous equality
    int current_char = str[0];
    int is_match = any(current_char, del, d_len);
    if (!is_match)
        pos++;
    previous_char = current_char;

    for (int i = 1; i < len; i++)
    {
        current_char = str[i];
        if (current_char != previous_char)
        {
            is_match = any(current_char, del, d_len);
        }
        if (!is_match)
            str[pos++] = current_char;
        previous_char = current_char;
    }
    str[pos] = TERM;
    return pos;
}

int any(char c, char *s, int s_len)
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
        printf("Usage: %s <Input string> <Delete sequence>\n", argv[0]);
        return 1;
    }
    int new_len = squeeze(argv[1], argv[2]);
    printf("Result: '%s' (%d)\n", argv[1], new_len);
}