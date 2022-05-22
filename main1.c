#include <stdio.h>
#include <stdlib.h>
void swapInt(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void insertionSort(int* Arr, int first, int last)
{
    int temp, locat;
    for (int i = first + 1; i <= last; i++)
        {
         int temp = Arr[i];
        locat = i - 1;
        while (locat >= first && Arr[locat] > temp)
        {
            Arr[locat + 1] = Arr[locat];
            locat = locat - 1;
        }
        Arr[locat + 1] = temp;

        }
}
int median(int *arr, int first, int last)
{
    int res;
    int min;
    int max;
    int mid = arr[(first + last) / 2];
    if (arr[first] > arr[mid])
        {
           min = arr[mid];
           max = arr[first];
        }
    else
        {
           min = arr[first];
           max = arr[mid];
        }
    if (min > arr[last])
    {
        res = min;
    }

    else if (arr[last] > max)
    {
        res = max;
    }

    else
        {
            res = arr[last];
        }

    if (res == arr[first])
        {
        return first;
        }
        else if (res == arr[mid])
        {
            return mid;
        }
    else return last;
}
void quicksort(int* arr, int first, int last)
{
    if (last - first > 10)
        {
        int med = median(arr, first, last);
        swapInt(&arr[med], &arr[(first + last) / 2]);
        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];
        do
        {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if(i <= j)
            {
                swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
        while (i <= j);

         quicksort(arr, i, last);
         quicksort(arr, first, j);
       }
       else
        {
         insertionSort(arr, first, last);
         return;
        }
}
void printArray(int *Arr, int len)
{
     for(int i = 0; i<len; i++)
     {
         printf("%4d", Arr[i]);
     }
     printf("\n");
}
void task1()
{
    printf("%s", "ishodniy massiv: ");
    int Arr[13] = {3,14,32,11,4,7,12,16,28,9,2,10,17};
    printArray(Arr, 13);
    quicksort(Arr, 0, 12);
    printf("%s", "sort massiv:     ");
    printArray(Arr, 13);
}
/////////TASK2////////////////////////////////////////////////////////////////////////////////////////////
void bucketSort(int* Array, int len) {
    const int max = len;
    const int b = 12;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i)
     {
        buckets[i][max] = 0;
     }

    for (int digit = 1; digit < 1000000000; digit*=10)
    {
        for (int i = 0; i < max; ++i)
            {
            if (Array[i] % 2 == 0)
                {
                int d = (Array[i] / digit) % b;
                buckets[d][buckets[d][max]++] = Array[i];
                Array[i] = -1;
                }
            }
        int idx = 0;
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < buckets[i][max]; ++j)
            {
                while (Array[idx] != -1) idx++;
                Array[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

void task2()
{
    printf("%s", "ishodniy massiv: ");
    int Array[12] = {0,2,8,3,4,6,5,9,8,2,7,3};
    printArray(Array, 12);
    bucketSort(Array, 12);
    printf("%s", "sort massiv:     ");
    printArray(Array, 12);
}
int main()
{
    task1();
    //task2();
    return 0;
}

