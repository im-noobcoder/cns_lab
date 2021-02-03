#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8000

void readfile(char *filename, char *filedata)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("file not found\n");
        exit(0);
    }
    
    int i=0;
    char ch;
    ch = fgetc(fp);
    while (ch != EOF)
    {
        filedata[i++] = ch;
        ch = getc(fp);
    }
    filedata[i] = '\0';
}

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char msg[1000], filedata[1000];
       
    server_fd = socket(AF_INET, SOCK_STREAM, 0);    //create the socket

    address.sin_family = AF_INET;   
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    bind(server_fd, (struct sockaddr *)&address,  sizeof(address));     //binding the socket and address

    listen(server_fd, 3);   //server can listen to 3 connections max at once

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);      //accepting a new connection

    read( new_socket , buffer, 1024);     //reading data from connection 
    printf("client is requesting for : %s\n",buffer ); 
    readfile(buffer, filedata);
    printf("sending file contents\n");
    send(new_socket , filedata , strlen(filedata) , 0 ); 

    return 0;
} 