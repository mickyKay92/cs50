#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet according to Scrabble
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Letters of the alphabet
char ALPHA[] = "abcdefghijklmnopqrstuvwxyz";

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

// Calculate the score for the user's string
int compute_score(string word)
{
    int score = 0;
    // Loop through length of the word provided and do the following:
    for (int i = 0; i < strlen(word); i++)
    {
        // Check that the character at word[i] is alphabetical, then:
        if (isalpha(word[i]))
        {
            // Store the individual letter as a lowercase letter
            char letter = tolower(word[i]);
            for (int j = 0; j < 26; j++)
            {
                /*If letter matches the iteration of ALPHA[i],
                increase score by the value at POINTS[j]*/
                if (letter == ALPHA[j])
                {
                    score += POINTS[j];
                }
            }
        }
    }
    return score;
}

