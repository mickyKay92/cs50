#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int start, end;
    int years = 0;
// Prompt user for starting number of llamas (eg: 9)
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
// Prompt user for ending number of llamas (eg: 18)
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
// Every year, 1/3 of the llamas are born and 1/4 pass away
    while (start < end)
    {
        start = start + trunc((start / 3)) - trunc((start / 4));
        // eg: 9  =  9   +   3  - 2
        years++;
    };
// How many years does it take to get to the goal population?
    printf("Years: %i\n", years);
}