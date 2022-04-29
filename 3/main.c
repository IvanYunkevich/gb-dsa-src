#include <stdio.h>
#include <locale.h>

 int main()
{

    int num;
    int var = 0;
    do
     {
       printf("%s", "Enter the number:");
       scanf ("%d", &num);
     } while ( num <= 0 );

     for (int i = 2; i <= (num / 2); i++)
     {
     if (num % i == 0)
     {
        var = 1;
     break;
     }
     }
if (var == 0)
{
  printf ("Prime number");
  return 0;
}
else
    printf ("%s", "The number is not prime");
 return 0;
}
