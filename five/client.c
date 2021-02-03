#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8000
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char msg[1000];
    char buffer[1024] = {0}; 

    sock = socket(AF_INET, SOCK_STREAM, 0);     //create a socket
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));    //connect to the server

    printf("enter the file name : ");
    scanf("%s", msg);
    send(sock , msg , strlen(msg) , 0 ); 
    read(sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
} 