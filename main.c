#include <stdio.h>
#include <stdlib.h>
#define SUM 98
//////Task1////////////////////////////////////////////////
int hash(char* Str)
{
    int codesSum = 0;
    while (*Str != '\0')
    {
        codesSum += *Str;
        Str++;
    }
    return codesSum;
}

///////////task2////////////////////////////////////////////

int coins(int* coin, int sum, const int SIZE)
{
    int var = 0;
    for (int i = 0; i < SIZE; i++)
    {
        while (coin[i] <= sum)
        {
            sum -= coin[i];
            var++;
            printf("%4d", coin[i]);
        }
        if (sum == 0)
        {
            continue;
        }
    }
    return var;
}
int main()
{
    int coin[] = {50, 10, 5, 2, 1};
    printf(coins(coin, SUM, 5));
    return 0;
}
