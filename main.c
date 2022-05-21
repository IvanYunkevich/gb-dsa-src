#include <math.h>
#include <stdio.h>
//это ласт
double f(double x)
{
    return sqrt(fabs(x)) + 5 * pow(x, 3);
}
void TPK()
{
        double a[11] = {0}, y;
    printf("%s", "Vvedite 11 chisel:");
    printf("\n");
    for (int i = 0; i <= 11; i++)
    {
        scanf("%lf", &a[i]);
    }
    for (int i = 10; i >= 0; i--)
        {
        y = f(a[i]);
        if (y > 400)
            printf("%d TOO LARGE\n", i);
        else
            printf("%d %.16g\n", i, y);
        }
}
int main()
{
    TPK();
    return 0;

}
