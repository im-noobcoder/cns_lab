#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8000

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0), length;
    struct sockaddr_in serveraddr;
    length = sizeof(serveraddr);
    char buffer[1024], message[100];

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    
    printf("enter message : ");
    scanf("%s", message);

    sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&serveraddr, length);
    int n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)NULL, NULL);
    buffer[n] = '\0';
    printf("got an acknowledgement : %s\n", buffer);
}