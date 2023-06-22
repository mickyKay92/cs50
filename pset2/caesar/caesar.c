/*
- Your program must accept a single command-line argument, a non-negative integer - Lets call it 'k' for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print
  an error message of your choice (with printf) and return from 'main' a value of '1' (which tends to signify an error) immediately.
- If any of the characters of the command-line argument is not a decimal digit, your program should print an error message prompting the user
  and return from 'main' a value of '1'.
- Do not assume that 'k' will be less than or equal to 26. Your program should work for all non-negative integral values of 
  'k' less than 2(31) - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for 'k'
  that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if 'k' is greater than 
  26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if 'k'
  is 27, A should not become '\' even though '\' is 27 positions away from 'A' in ASCII, per asciitable.com; 'A' should become 'B', since
  'B' is 27 positions away from 'A', provided you wrap around from 'Z' to 'A'.
- Your program must output 'plaintext:' and then prompt the user for a string of plaintext using get_string.
- Your program must output 'ciphertext:' followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the
  plaintext “rotated" by 'k' positions; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated,
  must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning '0' from 'main'.
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipherText(int key, string plaintext);

int main(int argc, string argv[])
{
    // If user CL argument is less than 2 arguments, prompt user and quit program
    if (argc != 2)
    {
        printf("Naming Convention should be: ./caesar [number]\n");
        return 1;
    }
    // If user CL argument contains anything other than digits, prompt user and quit program
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Naming Convention should be: ./caesar [number]\n");
            return 1;
        }
    }
    // If user CL argument is 2 arguments, ask user for plaintext input
    string plaintext = get_string("plaintext: ");
    // Convert user's CL argument to an integer
    int key = atoi(argv[1]);
    // Generates and prints the ciphertext
    cipherText(key, plaintext);
}

// Cypertext function with the user key and user input plugged into it
void cipherText(int key, string plaintextString)
{
    // Get plaintext length and store it for the encrypted character
    int plaintextLength = strlen(plaintextString);
    char encryptedString[plaintextLength];
    for (int i = 0; i < plaintextLength; i++)
    {
        /* If iteration is uppercase, convert to lowercase and skip ASCII
        non-letter characters */
        if (isupper(plaintextString[i]))
        {
            encryptedString[i] = (plaintextString[i] - 65 + key) % 26 + 65;
        }
        /* If iteration is lowercase, convert to uppercase and skip ASCII
        non-letter characters */
        else if (islower(plaintextString[i]))
        {
            encryptedString[i] = (plaintextString[i] - 97 + key) % 26 + 97;
        }
        // If iteration not a letter, leave the character unchanged
        else
        {
            encryptedString[i] = plaintextString[i];
        }
    }
    // Print the ciphertext
    printf("ciphertext: %s\n", encryptedString);
}