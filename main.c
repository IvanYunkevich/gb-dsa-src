#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define SZ 1000
#define T int
#define true 1==1
#define false 1!=1

typedef struct
{
    int pr;
    int dat;
} Node;
Node* array[SIZE];
int head;
int tail;
int items;

void init()
{
    for(int i = 0; i < SIZE; ++i)
    {
        array[i] = NULL;
    }
        head = 0;
        tail = 0;
        items = 0;
}
void ins(int pr, int dat)
{

	Node* node = (Node*) malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;

    if (items < SZ)
    {
        array[items++] = node;
    } else
    {
        printf("%s \n", "Queue is full");
        return;
    }
}
Node* rem()
{
    if (items == 0)
    {
        printf("%s\n", "Queue is empty");
        return NULL;
    }
    int idx = head++ % SIZE;

    for(int i = 0; i < SIZE; ++i)
    {
        if(array[i] == NULL)
        {
            continue;
        }
        if(array[i]-> pr > array[idx]-> pr)
        {
            idx = i;
        }
    }
    Node *t = array[idx];
    Node *temp;
    array[idx] = NULL;
    items--;

    for(int j = idx; j >= 1; j--)
    {
      temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
    }
    return t;
}
void printQueue()
{
    printf("[ ");
    for(int i = 0; i < SIZE; ++i)
    {
        if (array[i] == NULL)
            printf("[*, *] ");
        else
            printf(" [%d, %d] ", array[i]->pr, array[i]->dat);
    }
    printf(" ]\n");
}
void task1()
{
    init();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    printQueue();
       for (int i = 0; i < 2; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
   }
    printQueue();
    return 0;
}
/////Task2//////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef int boolean;
int cursor = -1;
T Stack[SZ];

boolean push(T data) {
	if (cursor < SZ)
	{
		Stack[++cursor] = data;
		return true;
	}
	else
	{
		printf("%s", "Stack overflow");
		return false;
	}
}

T popST() {
	if (cursor != -1)
	{
		return Stack[cursor--];
	}
	else {
		printf("%s", "Empty stack");
		return -1;
	}
}
boolean decToBinST(int x, char *res)
{
    do
    {
        push(x % 2);
        x = x / 2;

    }while (x >= 1);

    while (cursor != -1) {
        strcat(res, (popST()) ? "1" : "0");
    }
    strcat(res, "\0");
    return true;
}

void task2()
{
    char bin[35];
    boolean b = decToBinST(100, bin);
    printf("%s\n", bin);
}
int main()
{
    task1();
    //task2();
    return 0;
}
