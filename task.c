#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/////////////TASK1//////////////////////////////////////////////////////////////////////////////////////////////////////////
void bubbleSort(int Array[3][3], int Row, int Col)
{
    int temp;
        for(int a = 0; a < 3; a++)
            {
        for(int b = 0; b < 3; b++)
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(Array[a][b] < Array[i][j])
                    {
                        temp = Array[a][b];
                        Array[a][b] = Array[i][j];
                        Array[i][j] = temp;
                    }
                }
            }
        }
    }
}
void printArray(int Array[3][3], int Row, int Col)
{
       for (int i=0; i<Row; ++i)
   {
      for ( int j=0; j<Col; ++j)
      {
         printf("%d ", Array[i][j]);
      }
      printf("\n");
   }
}
task1()
{
            int Array[3][3] = {{1,9,2},{5,7,6},{4,3,8}};
        printf("%s", "ishodniy massiv");
   printf("\n");
   printArray(Array, 3, 3);
    printf("\n");
        printf("%s", "sort massiv:");
     printf("\n");
    bubbleSort(Array, 3, 3);
    printArray(Array, 3, 3);
}
//////////TASK2//////////////////////////////////////////////////////////////////////////////////////////////////
void TPK()
{
        double a[11] = {0};
    printf("%s", "Vvedite 11 chisel:");
    printf("\n");
    for (int i = 0; i <= 11; i++)
    {
        scanf("%lf", &a[i]);
    }
    for (int i = 10; i >= 0; i--)
        {
          if (sqrt(fabs(a[i]))+5*pow(a[i],3)>400)
           {
            printf("%d TOO LARGE\n", i);
           }
        else
           {
            printf("%d: %.2f\n",i+1,sqrt(fabs(a[i]))+5*pow(a[i],3));
           }

        }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //task1();
    TPK();

    return 0;
}
