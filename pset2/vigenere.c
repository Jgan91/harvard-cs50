#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    } 
    
    string k = argv[1];
    int klength = strlen(k);
    
    for (int a = 0; a < klength; a++) 
    {
        if (!isalpha(k[a]))
        {
            printf("only enter alphabetical characters\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string p = get_string();
    int plength = strlen(p);
    
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0; i < plength; i++)
    {
        if (j >= klength) {
            j = 0;
        }
        if (isalpha(p[i]))
       {
            if (isupper(p[i]))
            {
                if (isupper(k[j]))
                {
                    printf("%c", ((p[i] - 65 + (k[j] - 65)) % 26 + 65));
                } else 
                {
                    printf("%c", ((p[i] - 65 + (k[j] - 97)) % 26 + 65));
                }
            } else if (islower(p[i]))
            {
                if (isupper(k[j]))
                {
                    printf("%c", ((p[i] - 97 + k[j] - 65) % 26 + 97));
                } else
                {
                    printf("%c", ((p[i] - 97 + k[j] - 97) % 26 + 97));
                }
            } 
            j += 1;
        } else 
        { 
            printf("%c", p[i]);
        }
    }
    printf("\n");
}