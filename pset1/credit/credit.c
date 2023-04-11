#include <cs50.h>
#include <stdio.h>

/*
CS50 PSet1 - Credit https://cs50.harvard.edu/x/2023/psets/1/credit/
Michelle's Rating - Difficult
Rules:
User must input a valid card number.
The card must pass a checksum using Luhn's algorithm
The output must confirm which type of card that the user has provided
using the folowing definitions:
  American Express - 15 digits and starts with 34 or 37
  MasterCard - 16 digits and starts with 51, 52, 53, 54 or 55
  Visa - 13 or 16 digits and starts with 4
*/

// Function to get the product
int getProduct(int n)
{
  n *= 2;
  int temp = 0;

  if (n < 10)
  {
    return n;
  }
  else
  {
    while (n != 0)
    {
      temp += n % 10;
      n /= 10;
    }
    return temp;
  }
}

int main(void)
{
  // Store the card number from the user
  long cardLength, cardNumber, userInput = 0;
  int length = 0;
  do
  {
    userInput = get_long("Card Number: ");
  } while (userInput < 0);
  cardLength = userInput;
  cardNumber = userInput;

  // Count length of card number
  while (cardLength > 0)
  {
    cardLength /= 10;
    length++;
  }

  // Check if card is at least 13 digits long
  if (length != 13 && length != 15 && length != 16)
  {
    printf("INVALID\n");
    return 0;
  }

  // Getting checksum
  int multiply = 0;
  int sum = 0;

  bool isAltDigit = false;
  while (userInput != 0)
  {
    // This works with the second to last and every other digit
    int lastDigit = userInput % 10;

    if (isAltDigit == false)
    {
      // If the alternate digit is false, update sum w/ sum = sum + the last digit
      sum += lastDigit;
    }
    else
    {
      /* If the alternate digit is true, update multiply w/
      multiply = multiply + the product of last digit */
      multiply += getProduct(lastDigit);
    }
    isAltDigit = !isAltDigit;
    userInput = userInput / 10;
  }

  // Check last digit of sum below, determine if it's a 0
  int checksum = sum + multiply;
  if (checksum % 10 != 0)
  {
    printf("INVALID\n");
    return 0;
  }

  // Find first two digits of card number
  long start = cardNumber;
  do
  {
    start = start / 10;
  } while (start > 100);

  // Check for Mastercard ∴ 16 digits & starts w/ 51, 52, 53, 54 or 55
  if ((start >= 51 && start <= 55) && length == 16)
  {
    printf("MASTERCARD\n");
    return 0;
  }
  // Check for American Express ∴ 15 digits & starts w/ 34 or 37
  else if ((start == 34 || start == 37) && length == 15)
  {
    printf("AMEX\n");
    return 0;
  }
  // Check for Visa ∴ 13 or 16 digits & starts w/ 4
  do
  {
    start = start / 10;
  } while (start > 10);
  if ((length == 13 || length == 16) && start == 4)
  {
    printf("VISA\n");
    return 0;
  }
  // If none of the above, then the card is invalid
  else
  {
    printf("INVALID\n");
  }
  return 0;
}