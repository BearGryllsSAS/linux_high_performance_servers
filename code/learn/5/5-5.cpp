#include "wrap.h"

/**
 *  接受一个异常的连接
 * 
*/

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("usage: %s ip_address port_number\n", argv[0]);

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

    sleep(10);

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);

    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if (connfd < 0) 
    {
        printf("error is: %d\n", errno);
    }
    else 
    {
        char remote[INET_ADDRSTRLEN];

        printf("connected with ip: %s and port: %d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));
    }

    close(sock);

    return 0;
}
