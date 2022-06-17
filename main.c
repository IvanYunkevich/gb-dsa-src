#include <stdio.h>
#include <stdlib.h>
#define n 6
#define true 1==1
#define false 1!=1
#define T char
typedef int boolean;

int matrix[n][n] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0},
};
int visited[n] = {0};

typedef struct OneLinkNode
{
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct
{
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

boolean pushOneLinkStack(OneLinkList *stack, T value)
{
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
int get2dInt(int** array, const int row, const int col)
{
    return *((*(array + row)) + col);
}

T popOneLinkStack(OneLinkList *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}
///////1/////////////////////
int getUnvisitedVertex (int** matrix, int ver, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (get2dInt(matrix, ver, i) == 1 && !visited[i])
            return i;
    }
    return -1;
}
void resetArr()
{
    for (int i = 0; i < n; ++i)
    {
        visited[i] = 0;
    }
}
void depthTravers(int st)
{
    int r;
    printf("%d", st);
    visited[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visited[r]) {
            depthTravers(r);
        }
    }
}
void depthTraversStack(int** matrix, int size)
{
    OneLinkList* stack = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(stack);

    visited[0] = true;
    printf("%c ", 0 + 65);
    pushOneLinkStack(stack, 0);

    while (stack->size)
    {
        int v = getUnvisitedVertex(matrix, stack->head->dat, size);
        if (v == -1)
        {
            popOneLinkStack(stack);
        } else
        {
            visited[v] = true;
            printf("%c ", v + 65);
            pushOneLinkStack(stack, v);
        }
    }
    resetArr;
}
////////////////////////////////////////////////////////////////
int adjLinks[n] = {0};

void adjacencyMatrixCount (int** matrix, const int size)
{
    for (int i = 0; i < size; ++i)
        {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[j][i] == 1 && i != j)
                adjLinks[i]++;
        }
    }
}




int main()
{
    depthTravers(0);
    return 0;
}
