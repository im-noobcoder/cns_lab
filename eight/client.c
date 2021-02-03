#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"

int main()
{
    char filename[50], filedata[1000];
    int fd1, fd2,ch = 1, dataLength;
    mknod(FIFO1_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO2_NAME, S_IFIFO | 0666, 0);
    while (ch)
    {
        fd1 = open(FIFO1_NAME, O_WRONLY);
        printf("\nEnter file name : ");
        scanf("%s", filename);
        write(fd1, filename, strlen(filename));
        printf("\nwaiting for reply...\n");

        fd2 = open(FIFO2_NAME, O_RDONLY);
        dataLength = read(fd2, filedata, 1000);
        filedata[dataLength] = '\0';    //to remove the garbage content at the end of file
        printf("file contents are : \n\n %s \n", filedata);
        printf("\ndo you need another file? \t1.YES \t0.NO\n");
        scanf("%d", &ch);
    }
}