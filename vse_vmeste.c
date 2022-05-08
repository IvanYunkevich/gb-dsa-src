#include <stdio.h>
#include <stdlib.h>
//task1==================================
void toBin(int x)
{
    if (x < 2)
    {
        printf("%d", x);
    }
    else
    {
        toBin(x / 2);
        int var = x % 2;
        printf("%d", var);
    }
}
//task2==================================
int task2(int a, int b)
{
    int var = a;
    if (a == 0)
    {
        printf("%s", "0");

    }
    else if (a == 1)
    {
        printf("%s", "1");
    }

    else if (b == 0)
         printf("%s", "1");
    else
    {
     for (int i = 1; i < b; i++)
     {
       var = a * var;
     }
     		printf("%d", var);
    }
}
//task3==================================
int task3(int a, int b)
{

    if (b == 0)
    {
       return 1;
    }
    if (b > 0)
    {
      return a * task3(a, b -1);
    }

}
//task4==================================
int task4(int a, int b)
{
   int var = 0;
   if (a == 0)
   {
       return 0;
   }
    else if (b == 0)
    {
       return 1;
    }
    if (a > 0 && b >= 1 && b % 2 == 0)
   {
     var = a * task4(a, b / 2);
   }
     if (a > 0 && b >= 1 && b % 2 == 1)
    {
     var = a * task4(a, b - 1) * a;
    }
        return var;
}
int stepsOfKing()
{
    int step = 0;

    int field[3][3] = {1,1,1,1,1,0,1,0,0}; //1 - prepyadstvie
    field [1][1] == 1;
    for ( int x = 0; x < 3; x++ )
    {
       for ( int y = 0; y < 3; y++ )
       {
      if ( field[x][y] == 0 )
        step++;
       }
    }
return step;
}
int main()
{
     int x;
     int a;
     int b;
    //task1=============================
     printf("%s", "Enter the number");
     scanf("%d", &x);
	 toBin(x);
    //task2=============================
     printf("%s", "Enter number a:");
     scanf("%d", &a);
     printf("%s", "Enter number b:");
     scanf("%d", &b);
     printf("%d", task2(a, b));
     //task3=============================
    printf("%s", "Enter number a:");
    scanf("%d", &a);
    printf("%s", "Enter number b:");
    scanf("%d", &b);
    printf("%d", task3(a, b));
    //task4=============================
    printf("%s", "Enter number a:");
    scanf("%d", &a);
    printf("%s", "Enter number b:");
    scanf("%d", &b);
    printf("%d", task4(a, b));
    //task5=============================
    printf("%s%d","hodov:", stepsOfKing());

    return 0;
}
