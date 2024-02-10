#include "wrap.h"

/**
 *  backlog 参数
 * 
*/

static bool stop = false;

static void handle_term(int sig) 
{
    stop = true;
}

int main(int argc, char* argv[]) 
{
    signal(SIGTERM, handle_term);

    if (argc != 4) 
    {
        printf("usage: %s ip_address port_number backlog\n", basename(argv[0]));

        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int backlog = atoi(argv[3]);

    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock != -1);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    while (!stop) 
    {
        sleep(1);
    }

    close(sock);

    return 0;
}
