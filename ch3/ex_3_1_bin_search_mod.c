#include <stdio.h>
int binsearch_mod(int x, int v[], int n);

int binsearch_mod(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n;

    while (low < high)
    {
        mid = low + ((high - low) / 2);
        if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return (low < n && v[low] == x) ? low : -1;
}