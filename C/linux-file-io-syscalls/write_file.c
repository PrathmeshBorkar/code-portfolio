#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = 0;
    int ret = 0;
    char arr[] = "Marvellous Infosystems";

    fd = open("Marvellous.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File has been opened with fd : %d\n",fd);

        ret = write(fd,arr,10);
        printf("Number of bytes written : %d\n",ret);
    }

    return 0;
}