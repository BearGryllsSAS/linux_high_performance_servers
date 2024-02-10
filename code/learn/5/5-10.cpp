#include "wrap.h"

/**
 *  修改 tcp 发送缓冲区的客服端程序
 * 
*/

#define BUFFER_SIZE 512

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("usage: %s ip_address port_number senbuf_len\n", basename(argv[0]));

        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_ddress;
    bzero(&server_ddress, sizeof(server_ddress));
    server_ddress.sin_family = AF_INET;
    server_ddress.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_ddress.sin_addr.s_addr);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock != -1);

    int sendbuf = atoi(argv[3]);
    int len = sizeof(sendbuf);
    setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &sendbuf, len);
    getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &sendbuf, (socklen_t*)&len);
    printf("the tcp sen buffer size after setting is %d\n", sendbuf);

    int ret = connect(sock, (struct sockaddr*)&server_ddress, sizeof(server_ddress));
    if (ret < 0) 
    {
        printf("connection failed\n");
    }
    else
    {
        char buffer[BUFFER_SIZE];

        memset(&buffer, 'a', sizeof(buffer));

        send(sock, buffer, BUFSIZ, 0);
    }

    close(sock);

    return 0;
} 
