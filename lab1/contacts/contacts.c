#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Hi! What is your name?\n");
    int age = get_int("Pleased to meet you! How old are you?\n");
    string phone = get_string("What is your phone number?\n");

    printf("Thank you for confirming, %s! I can confirm that you are %i years old and we can contact you on %s if we ever need to reach out!\n", name, age, phone);
}