/*
For this problem, you’ll implement a program that calculates the approximate grade level
needed to comprehend some text using Coleman-Liau index.

    - Implement your program in a file called readability.c in a directory called readability.
    - Your program must prompt the user for a string of text using get_string.
    -  Your program should count the number of letters, words, and sentences in the text.
    - You may assume that a letter is any lowercase character from a to z or any uppercase character
      from A to Z, any sequence of characters separated by spaces should count as a word, and that
      any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    - Your program should print as output "Grade X" where X is the grade level computed by the
      Coleman-Liau formula, rounded to the nearest integer.
    - If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate
      reading level), your program should output "Grade 16+" instead of giving the exact index number.
      If the index number is less than 1, your program should output "Before Grade 1".
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for some text
    string text = get_string("Text: ");

    // Coleman-Liau index = 0.0588 * average letters per 100 words - 0.296 * average sentences per 100 words - 15.8
    float L = (double) count_letters(text) / (double) count_words(text) * 100;
    float S = (double) count_sentences(text) / (double) count_words(text) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Variations of printed results based on user's grade.
    if (index >= 16) // Print 'Grade 16+' if user's result is greater than or equal to 16
    {
        printf("Grade 16+\n");
    }
    else if (index < 1) // Print 'Before Grade 1' if user's result is less than 1
    {
        printf("Before Grade 1\n");
    }
    else // Print user's grade
    {
        printf("Grade %i\n", index);
    }
}

// Count the number of letters in the user's input
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count the number of words in the user's input
int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    // +1 due to final word drop-off
    return words + 1;
}

// Count the number of sentences in the user's input
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}