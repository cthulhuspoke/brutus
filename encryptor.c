/* a short hash creation program leveraging the crypt() function in C */

#define _XOPEN_SOURCE       
#include <unistd.h>
#include <stdio.h>

char text[4],salt[2];

int main (void)
{
    printf("Enter some text: \n");
    scanf("%s", text);
    printf("Enter a number: \n");
    scanf("%s", salt);
    char* crypted = crypt(text, salt);
    printf("%s \n", crypted);
    return (0); 
}
