#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, row, column, space;
    // Ask user to provide number between 1 and 8 until condition is met
    do
    {
        height = get_int("What height is the pyramid? ");
    }
    while (height < 1 || height > 8);
    // Create a row that is as long as the user's input
    for (row = 0; row < height; row++)
    {
        // Create a space for right alignment
        for (space = height; space > row; space--)
        {
            if (space < height)
            {
                printf(" ");
            };
        }
        // Create a new column every time 'row' is increased
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}