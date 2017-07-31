#include <cs50.h>
#include <stdio.h>

void print_row(int height, int n);
void print_spaces(int height, int n);
void print_blocks(int n);

int main(void)
{
    printf("Height: ");
    int height = get_int();
    while (height < 0 || height > 23) 
    {
        printf("Height: ");
        height = get_int();
    }
    
    for (int i = 0; i < height; i++)
    {
        print_row(height, i);
    }
}

void print_row(int height, int n)
{
    print_spaces(height, n);
    print_blocks(n);
    printf("  ");
    print_blocks(n);
    print_spaces(height, n);
    printf("\n");
}

void print_spaces(int height, int n)
{
    for (int i = 0; i < height - n - 1; i++)
    {
        printf(" ");
    }
}

void print_blocks(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("#");
    }
}