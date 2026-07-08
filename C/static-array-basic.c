#include<stdio.h>

int main()
{
    //Static memory allocation
    float Marks[5];     //20 bytes
    
    printf("Enter your marks : ");
    
    scanf("%f",&Marks[0]);
    scanf("%f",&Marks[1]);
    scanf("%f",&Marks[2]);
    scanf("%f",&Marks[3]);
    scanf("%f",&Marks[4]);

    return 0;
}