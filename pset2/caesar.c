#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // print error if user doesn't input argv
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    
    // store input as k 
    int k = atoi(argv[1]);
    
    // ask user for plaintext input
    printf("plaintext: ");
    string p = get_string();
    
    printf("ciphertext: ");
    
    // iterate over characters in input
    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                // print rotated letter by k positions 
                printf("%c", ((p[i] - 65 + k) % 26 + 65));
            } else if (islower(p[i]))
            {
                printf("%c", ((p[i] - 97 + k) % 26 + 97));
            } 
        } else 
        { 
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
}