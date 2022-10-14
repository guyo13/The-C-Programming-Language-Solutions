#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define RANGE '-'

void copy(char start_char, int count, int offset, char *arr);
int _expand(char *s1, char *s2, void (*cb)(char, int, int, char *));
void expand(char *s1, char *s2);

/// @brief Generates a range of increasing characters.
/// @param start_char The starting char
/// @param count The length of the sequence
/// @param offset The sequence offset
/// @param arr The target string buffer
void copy(char start_char, int count, int offset, char *arr)
{
    for (int i = 0; i < count; i++)
        arr[offset + i] = start_char + i;
}

/// @brief Implements the expansion logic calling `cb` when expansion needs to happen -
/// with the starting character, range length and target array pointer.
/// @param s1 The expansion sequence
/// @param s2 The target string buffer
/// @param cb Expansion handler
/// @return The length of s2.
int _expand(char *s1, char *s2, void (*cb)(char, int, int, char *))
{
    int s1len = strlen(s1);
    int i, next_pos;
    i = next_pos = 0;
    char start, end;
    // TODO implement logic
    while (i < s1len)
    {
        start = s1[i++];
        if (start == RANGE)
        {
            cb(RANGE, 1, next_pos, s2);
            ++next_pos;
            continue;
        }
        else if (!isalnum(start))
        {
            // printf("Skipping %c\n", start);
            continue;
        }
        // TODO - test
        end = i < s1len ? s1[i] : start;

        if (end == RANGE)
        {
            // If `end` is a trailing RANGE character (meaning its the last char) take it literaly
            if (i == s1len - 1)
            {
                cb(RANGE, 1, next_pos, s2);
                ++next_pos;
                continue;
            }
            else
            {
                // We matched a range (of the form 'x-y'). Handle it.
                end = s1[++i];
                int char_distance = end - start;

                if (char_distance > 0)
                {
                    cb(start, char_distance, next_pos, s2);
                    next_pos += char_distance - 1;
                }
                else
                {
                }
            }
        }
        else
        {
            // If `end` is not a RANGE character the range is trivial - meaning it consists of `start` only.
            cb(start, 1, next_pos, s2);
            ++next_pos;
            continue;
        }
    }
    return next_pos;
}

/// @brief Implements expansion logic that copies the output to s2.
/// @param s1 The expansion sequence
/// @param s2 The target string buffer
void expand(char *s1, char *s2)
{
    int s2_len = _expand(s1, s2, copy);
    // Copy \0 to terminate the sequence
    s2[s2_len] = '\0';
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <s1>\n", argv[0]);
        return 1;
    }

    char *s1 = argv[1];
    int s2_len = _expand(s1, NULL, NULL);
    // Add space of the null termination
    int s2_size = s2_len + 1;
    char *s2 = malloc(sizeof(char) * s2_size);
    expand(s1, s2);
    printf("s1: %s\ns2: %s\n", s1, s2);
}