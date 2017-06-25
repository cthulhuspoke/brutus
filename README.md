# brutus:
A simple C program that will find the 1 to 4 character long plaintext made up of any letter,  number and special character combination, of a hash.

# Test hashes:  
    
    // plaintext = hash 
    //
    // a         = 50OqznXGVcOJU
    // ab        = 50kiZhZaSRp0E
    // abc       = 50PaJ4.RO0YUo
    // abcd      = 50W9/ghfUb5j.
    
    
# To compile under Linux:

   $ clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow brutus.c -lcrypt -lcs50 -lm -o brutus

# Here are some times for those interested in them:

a = 50OqznXGVcOJU
real    0m0.003s
user    0m0.000s
sys     0m0.000s

ab = 50kiZhZaSRp0E
real    0m0.004s
user    0m0.000s
sys     0m0.004s

abc = 50PaJ4.RO0YUo
real    0m0.035s
user    0m0.032s
sys     0m0.000s

abcd = 50W9/ghfUb5j.
real    0m2.869s
user    0m2.856s
sys     0m0.004s

