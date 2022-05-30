#include <stdio.h>
#include <stdlib.h>
#define true 1==1
#define false 1!=1
#define T int
typedef int boolean;
typedef struct Node {
	int data;
	struct Node *next;
}Node;
typedef struct {
	Node *head;
	int size;

}List;
void ins(List *list, int data)
{
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    Node *current = list->head;
    if (current == NULL)
    {
        list->head = new;
        list->size++;
    }
    else
    {
        while (current->next != NULL)
       {
            current = current->next;
        }
        current->next = new;
        list->size++;
    }
}
boolean push(List *stack, T value)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf("Stack overflow \n");
        return false;
    }
    tmp->data = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(List *list) {
    if (list->size == 0)
    {
        printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = list->head;
    T var = list->head->data;
    list->head = list->head->next;
    free(tmp);
    list->size--;
    return var;
}
void initList(List *lst) {
    lst->head = NULL;
    lst->size = 0;
}
void printNode(Node *n)
{
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->data);
}
void printList(List *list)
{
    Node *current = list->head;
    if (current == NULL)
     {
        printNode(current);
     } else {
        do {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", list->size);
}
///////Task1////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int brackets(char* sig)
{
    const int TYPES = 3;
    char brackets[][2] = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    List *sm = (List*) malloc(sizeof(List));
    initList(sm);
    int idx = 0;
    while (*sig != '\0')
    {
        for (int i = 0; i < TYPES; ++i)
          {
             if (*sig == brackets[i][0])
             {
                push(sm, i);
             }
          }
        for (int i = 0; i < TYPES; ++i)
          {
            if (*sig == brackets[i][1])
             {
                if (sm->size == 0)
                 {
                    return idx;
                 }
                if (i == sm->head->data)
                  {
                     pop(sm);
                  }
                else
                  {
                     return idx;
                  }
             }
         }
        sig++;
        idx++;
    }
        if (sm->size != 0)
        {
            return sm->head->data;
        }
    return -1;
}
void task1()
{
    printf("%d \n", brackets("( ( [ )} [ [ { () ] ) )"));
    printf("%d \n", brackets("[2/{5*(4+7)}]"));
}
/////////Task2////////////////////////////////////////////////////////////////////////////////////////////////////////
void copyList(List* firstList, List* lastList)
{
 	Node* current = firstList->head;
 	if (current == NULL)
     {
        return;
     }

    push(lastList, current->data);
    Node* newNode = lastList->head;

    while (current->next != NULL)
        {
        Node *temp1 = (Node*) malloc(sizeof(Node));
        if (temp1 == NULL)
          {
             printf("Stack overflow \n");
             return;
          }
        temp1->data = current->next->data;

        newNode->next = temp1;
    temp1->next = NULL;
    current = current->next;
    newNode = temp1;
    lastList->size++;
    }
}

//////Task3////////////////////////////////////////////////////////////////////////////////////////
boolean sort(List* list)
{
    boolean var1 = true;
    Node *current = list->head;
    while (current->next != NULL)
    {
       if (current->data > current->next->data)
       {
         var1 = false;
       }
        current = current->next;
    }
    return var1;
}
int main()
{
    task1();
    //Task2
        List* firstList = (List*)malloc(sizeof(List));
    initList(firstList);
    List* lastList = (List*)malloc(sizeof(List));
    initList(lastList);
    for (int i = 5; i > 1; --i)
    {
        push(firstList, i);
    }
      copyList(firstList, lastList);
      printList(firstList);
      printList(lastList);
      //task3
    printf("%s \n", sort(firstList) ? "1" : "0");
    return 0;
}
