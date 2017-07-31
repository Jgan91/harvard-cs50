#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("O hai! How much change is owed? ");
    float change = get_float();
    while (change < 0)
    {
        printf("O hai! How much change is owed? ");
        change = get_float();
    }
    
    
    int cents = round(change * 100);

    int coins = 0;

    if (cents / 25 != 0)
    {
        coins += cents / 25;
        cents = cents % 25;
    }

    if (cents / 10 != 0)
    {
        coins += cents / 10;
        cents = cents % 10;
    }

    if (cents / 5 != 0)
    {
        coins += cents / 5;
        cents = cents % 5;
    }

    if (cents / 1 != 0)
    {
        coins += cents / 1;
        cents = cents % 1;
    }
    
    printf("%i\n", coins);
}