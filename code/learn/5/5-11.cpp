#include "wrap.h"

/**
 *  修改 tcp 接收缓冲区的服务器程序
 * 
*/

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) 
{

    if (argc != 3) 
    {
        printf("usage: %s ip_address port_number recvbuf_len\n", basename(argv[0]));

        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock != -1);

    int recvbuf = atoi(argv[3]);
    int len = sizeof(recvbuf);
    setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &recvbuf, sizeof(recvbuf));
    getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &recvbuf, (socklen_t*)&len);
    printf("the tcp receive buffer size after setting is % d\n", recvbuf);

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);
    
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);

    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if (connfd < 0) 
    {
        printf("errno is: %d\n", errno);
    }
    else 
    {
        char buffer[BUFSIZ];

        memset(&buffer, '\0', sizeof(buffer));

        while (recv(connfd, buffer, BUFSIZ - 1, 0) > 0) {}

        close(connfd);
    }

    close(sock);

    return 0;
}
