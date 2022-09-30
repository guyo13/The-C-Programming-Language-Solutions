// The C Programming language EX 1-13

#include <stdio.h>
#include <stdlib.h>
#define HOZ 'h'
#define VER 'v'

int max(int *arr, int len)
{
    int m = arr[0];
    for (int i = 1; i < len; i++)
    {
        int num = arr[i];
        if (num > m)
        {
            m = num;
        }
    }
    return m;
}

void format_horizontal(int *hist, int len)
{
    for (int i = 0; i < len; i++)
    {
        int count = hist[i];
        for (int j = 0; j < count; j++)
        {
            putchar('=');
        }
        putchar('\n');
    }
}

void format_vertical(int *hist, int len)
{
    int m = max(hist, len);
    for (int height = m; height > 0; height--)
    {
        for (int column = 0; column < len; column++)
        {
            int bin_count = hist[column];
            if (bin_count >= height)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('\n');
    }
}

void format(int *hist, int len, char formatting)
{
    formatting == HOZ ? format_horizontal(hist, len) : format_vertical(hist, len);
}

int get_bin_index(int value, int bins, int bin_size)
{
    // Assuming the first bin start at 1 and not at 0.
    // If 0 is given to this function it will always go to the first bin.
    int value_for_bin = value > 0 ? value - 1 : value;
    int theo_bin_number = value_for_bin / bin_size;
    // Anything bigger than bins * bin_size goes to the last bin.
    int bin_index = theo_bin_number >= bins ? bins - 1 : theo_bin_number;
    return bin_index;
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Help: %s <bins> <bin size> <formatting>\n", argv[0]);
        return 1;
    }
    int bins = strtol(argv[1], NULL, 10);
    int bin_size = strtol(argv[2], NULL, 10);
    char formatting = argv[3][0];
    if (formatting != HOZ && formatting != VER)
    {
        printf("Fromatting must be 'v' or 'h' got '%c'\n", formatting);
    }
    printf("Bins: %d\n", bins);
    printf("Bin size: %d\n", bin_size);
    printf("Formatting: %s\n", formatting == HOZ ? "Horizontal" : "Vertical");
    int *hist = malloc(bins * sizeof(int));
    int frequencies[256];
    for (int i = 0; i < 256; i++)
    {
        frequencies[i] = 0;
    }

    int read_c;
    int word_len = 0;

    while ((read_c = getchar()) != EOF)
    {
        frequencies[read_c] = frequencies[read_c] + 1;
    }
    for (int i = 0; i < 256; i++)
    {
        int char_freq = frequencies[i];
        if (char_freq > 0)
        {
            int bin_index = get_bin_index(char_freq, bins, bin_size);
            hist[bin_index] = hist[bin_index] + 1;
        }
    }

    format(hist, bins, formatting);
    free(hist);
}