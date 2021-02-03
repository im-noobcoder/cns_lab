#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"

//function to read a file and transfer it's contents to a char array
void readfile(char *filename, char * filedata) 
{
    FILE *fp = fopen(filename, "r");
    char ch;
    int i=0; 
    ch = fgetc(fp);
    while (ch != EOF)
    {
        filedata[i++] = ch;
        ch = fgetc(fp);
    }
    filedata[i] = '\0';
}

int main()
{
    char filename[50], filedata[1000], ch;
    int fd1, fd2, file1, namelength;
    mknod(FIFO1_NAME, S_IFIFO | 0666, 0);
    mknod(FIFO2_NAME, S_IFIFO | 0666, 0);
    fd1 = open(FIFO1_NAME, O_RDONLY);
    while(1)
    {
        namelength = read(fd1, filename, 50);
        filename[namelength] = '\0';
        file1 = open(filename, O_RDONLY);
        if (file1 < 0)
            {
                printf("\n%s not found\n", filename);
                exit(0);
            }
        printf("\nrequest for %s\n", filename);
        readfile(filename, filedata);
        fd2 = open(FIFO2_NAME, O_WRONLY);
        write(fd2, filedata, strlen(filedata));
        printf("data sent.\n waiting for another request...");
    }
}
