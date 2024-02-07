 #include "wrap.h"

/**
 *  发送带外数据
 * 
*/

int main(int argc, char* argv[]) {

    if (argc < 3) {

        printf("usage: %s ip_address port_number\n", argv[0]);

        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_address.sin_addr);

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sockfd != -1);

    int ret = connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (ret < 0) {

        // printf("connection failed\n");

        perror("connect error");
    }
    else {

        printf("send obb date out\n");

        const char* obb_data = "abc";
        const char* normal_data = "123";

        send(sockfd, normal_data, strlen(normal_data), 0);
        send(sockfd, obb_data, strlen(obb_data), MSG_OOB);
        send(sockfd, normal_data, strlen(normal_data), 0);
    }

    close(sockfd);

    return 0;
}
