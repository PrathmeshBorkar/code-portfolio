#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    close(0);
    return 0;  
}