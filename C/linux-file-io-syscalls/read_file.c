#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h>

int main()
{
    int fd = 0;
    int ret = 0;
    char arr[20];

    fd = open("Marvellous.txt",O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File has been opened with fd : %d\n",fd);

        ret = read(fd,arr,6);
        printf("Number of bytes read : %d\n",ret);
        printf("Data from file is : %s\n",arr);
    }

    return 0;
}