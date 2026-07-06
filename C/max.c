#include <stdio.h>

int findMax(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n1, n2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    max = findMax(n1, n2);

    printf("Maximum number is: %d\n", max);

    return 0;
}
