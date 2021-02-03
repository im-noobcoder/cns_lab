//sliding window protocol

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
    int serverSocket, connection;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    int addrlen = sizeof(serverAddress);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    listen(serverSocket, 1);
    connection = accept(serverSocket, (struct sockaddr *)&serverAddress, (socklen_t*)&addrlen);

    while (1)
    {
        char buffer[1024] = {0};
        char ack[1024] = {0};
        printf("\nenter datagram ('exit' to close connection) : ");
        scanf("%s", buffer);
        if (strcmp("exit", buffer) == 0)
        {
            send(connection, (char *)"exit", strlen("exit"), 0);
            close(connection);
            return 0;
        }
        else
        {
            send(connection, buffer, strlen(buffer), 0);
            read(connection, ack, 1024);
            printf("client sent acknowledgement : %s\n", ack);
        }

    }
}
