//16//
#include <stdio.h>
#include <stdlib.h>
////////task1///////////////////////////////////////////
void cesarCrypt(char *str, int key)
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] += key;
        i++;
    }
}
void cesarDecrypt(char *str, int key)
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] -= key;
        i++;
    }
}
void printString(char* str, int size)
{
	for (int i = 0; i < size; i++)
		printf("%c", str[i]);
}
void task1()
{
    char str[20] = "Ananas";
    printString(str, 6);
    printf(" \n");
    cesarCrypt(str, 4);
    printString(str, 6);
    printf(" \n");
    cesarDecrypt(str, 4);
    printString(str, 6);
}
//второе задание не успел за день сделать, поэтому буду разбирать самостоятельно за время буткемпа.
int main()
{
    task1();

    return 0;
}
