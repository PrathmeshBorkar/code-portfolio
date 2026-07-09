#include<stdio.h>
//Call by address
int strlenx(char *ptr)
{
    int count = 0;

    while(*ptr!='\0')
    {
        count++;
        ptr++;
    }

    return count;
}

int main()
{
    char str[] = "Ganesh";
    int ret = 0;

    ret = strlenx(str);

    printf("Length of String : %d\n",ret);

    return 0;
}