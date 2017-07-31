#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    // ask user for name
    string input = get_string();
    int inputlen = strlen(input);
    
    // check if first char is not a space
    if (input[0] != ' ')
    {
        printf("%c", toupper(input[0]));
    }
    
    for (int i = 0; i < inputlen; i++)
    {
        if (input[i] == ' ' && input[i+1] != ' ')
        {
            printf("%c", toupper(input[i+1]));
        }
    }
    printf("\n");
}