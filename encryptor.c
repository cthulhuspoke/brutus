/* A short program to create hashes using the crypt() function */

#define _XOPEN_SOURCE       
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Enter some text: \n");
    string text = get_string();
    printf("Enter a number: \n");
    string salt = get_string();
    printf("%s \n",text);
    string crypted = crypt(text, salt);
    printf("%s \n", crypted);
    return 0;
}
