#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while ((n < 1) || (n > 8));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            printf(" "); // spaces
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#"); // left half-pyramid
        }
        printf("  "); // gap
        for (int c = 0; c <= i; c++)
        {
            printf("#"); // right half-pyramid
        }
        printf("\n");
    }
}
