#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8000

int main()
{
    int serverfd = socket(AF_INET, SOCK_DGRAM, 0), length;
    char buffer[1024], message[] = "got your message";
    struct sockaddr_in serveraddr, clientaddr;
    length = sizeof(clientaddr);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    while(1)
    {
        int n = recvfrom(serverfd, buffer, 1024, 0, (struct sockaddr *)&clientaddr, (socklen_t*)&length);
        buffer[n] = '\0';
        printf("from client : %s\n", buffer);
        sendto(serverfd, message, strlen(message), 0, (struct sockaddr*)&clientaddr, length);
    }
}
