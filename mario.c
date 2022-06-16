#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, space, dif = 1;

    // Prompt user for height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Determine the initial required space for each line
    space = n - 1;

    // For each row
    for (int i = 0; i < n; i++)
    {
        // For each column
        for (int y = 0; y < 2; y++)
        {
            // To distinguish between first and second pyramids
            if (y == 0)
            {
                // Print required amount of space for each line
                for (int z = 0; z < space; z++)
                {
                    printf(" ");
                }
            }

            // Print double space between the pyramids
            else
            {
                printf("  ");
            }

            // Print a brick
            for (int x = 0; x < dif; x++)
            {
                printf("#");
            }
        }
        printf("\n");
        dif++;
        space--;
    }
}
