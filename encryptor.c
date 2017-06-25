/* a short hash creation program leveraging the crypt() function in C */

#define _XOPEN_SOURCE       
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    
    if(argc != 3)
    {
        printf("Usage: ./encryptor plaintext salt\n");
        return 1;
    }
    
    char *text = argv[1];
    char *salt = argv[2];
    char *crypted = crypt(text, salt);
    printf("Your hashed password is: %s\n", crypted);
    return (0); 
}
