// sliding window protocol

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 8000

int main()
{
    int clientSocket, i=0;
    struct sockaddr_in serverAddress;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1)
    {
        char buffer[1024] = {0};
        read(clientSocket, buffer, 1024);
        if (strcmp("exit", buffer) == 0)
            {
                close(clientSocket);
                return 0;
            }
        printf("received datagram %d : %s\n", i++, buffer);
        if (strlen(buffer) > 10)
            send(clientSocket, (char *)"positive", strlen("positive"), 0 ); 
        else
            send(clientSocket, (char *)"negative", strlen("negative"), 0);
    }
}