#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = 0;
    fd = creat("Marvellous.txt",0666);

    if (fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File has been created with fd : %d\n",fd);
    }
    return 0;
}