#include<stdio.h>

int main()
{
    char str[] = "Ganesh";
    char *ptr = NULL;

    ptr = str;                  //100

    printf("%c\n",*ptr);        //G
    ptr++;                      //101

    printf("%c\n",*ptr);        //a
    ptr++;                      //102

    printf("%c\n",*ptr);        //n
    ptr++;                      //103

    ptr = ptr + 3;              //106
    printf("%c\n",*ptr);        // \0

    return 0;
}