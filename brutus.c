/* A very simple program that will find the 1 to 4 character long plaintext, consisting of any letter, 
number and special character combination, of a hash. */

#define _XOPEN_SOURCE 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%%^&*()_+-=~`{}[]:\"\\;\'<>,.?/|\\";
int alphaSize= sizeof(alphabet) - 1;             // the size of the "alphabet" minus the trailing null zero
char str[4];                                     // array of the plaintext to be compared 
int index=0;                                     // index size variable for keeping track of the number of characters in str
char salt[2];                                    // the salt array which gets stripped off of the hash 

int main (int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./crack hash \n");
        return 1;
    }
    
    char* hash = argv[1];
    strncpy(salt, hash, 2);                      //strips the first two chars from the hash (Thanks John!)
    printf("the hash is: %s\n", hash);
    printf("the salt is: %s\n", salt);

    for (int i = 0; i < alphaSize; ++i)          // loop 1 for single character plaintext
    {
      str[index]=alphabet[i];
      if (strcmp(hash, crypt(str, salt)) == 0 )  //this is the comparison function aka "solve" (thanks Mike!)
      {
      printf("%s \n",str);                       //exit (0) quits the program as soon as the solve is complete (thanks Mike!)  
      exit (0);
      }
    } 
    for (int j = 0; j < alphaSize; ++j)          // loop 2 for double character plaintext
    {
      str[index] = alphabet[j];
      for (int k = 0; k < alphaSize; ++k)
      {
          str[index + 1] = alphabet[k];
          if (strcmp(hash, crypt(str, salt)) == 0 )      
          {                                        
           printf("%s \n",str);
           exit (0);
          }
      }
    }
    for (int i = 0; i < alphaSize; ++i)          // loop 3 for triple character plaintext
    {
        str[index] = alphabet[i];
        for(int j = 0; j < alphaSize; ++j)
        {
            str[index + 1] = alphabet[j];
            for(int k = 0; k < alphaSize; ++k)
            {
                str[index + 2] = alphabet[k];
                if (strcmp(hash, crypt(str, salt)) == 0 )      
                {                                        
                printf("%s \n",str);
                exit (0);
                }
            }
        }
    }
   for (int i = 0; i < alphaSize; ++i)           // loop 4 for quadruple character plaintext
    {
        str[index] = alphabet[i];
        for(int j = 0; j < alphaSize; ++j)
        {
            str[index + 1] = alphabet[j];
            for(int k = 0; k < alphaSize; ++k)
            {
                str[index + 2] = alphabet[k];
                for (int l = 0; l < alphaSize; ++l)
                {
                    str[index + 3] = alphabet[l];
                    if (strcmp(hash, crypt(str, salt)) == 0 )      
                    {                                        
                     printf("%s \n",str);
                     exit (0);
                    }
                }
                
            }
        }
    } 
    return 0;
 }
