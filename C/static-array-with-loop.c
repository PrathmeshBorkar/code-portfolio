#include<stdio.h>

int main()
{
    //Static memory allocation
    float Marks[5];     //20 bytes
    
    printf("Enter your marks : \n");
    
    scanf("%f",&Marks[0]);
    scanf("%f",&Marks[1]);
    scanf("%f",&Marks[2]);
    scanf("%f",&Marks[3]);
    scanf("%f",&Marks[4]);

    printf("\nEntered marks are : ");
    printf("\n%f",Marks[0]);
    printf("\n%f",Marks[1]);
    printf("\n%f",Marks[2]);
    printf("\n%f",Marks[3]);
    printf("\n%f",Marks[4]);

    return 0;
}