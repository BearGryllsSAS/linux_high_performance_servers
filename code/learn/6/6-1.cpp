#include "wrap.h"

/**
 *  CGI 服务器原理
 * 
*/

int main(int argc, char* argv[]) 
{

    if (argc != 3) 
    {
        printf("usage: %d ip_address port_number\n", basename(argv[0]));

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

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    struct sockaddr_in client;
    socklen_t client_addrlength;

    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if (connfd < 0) 
    {
        printf("errno is: %d\n", errno);
    }
    else 
    {
        close(STDOUT_FILENO);

        dup(connfd);

        printf("客户端向服务器发来信息\n");

        close(connfd);
    }

    close(sock);

    return 0;
}
