/*

C program to create a socket and bind to the port 8080

*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd  == -1){
        perror("Error:");
        exit(1);
    }
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = bind(server_fd, (const struct sockaddr *)&address, sizeof(address));
    if(result == -1){
        perror("Bind failed:");
        exit(1);
    }
    printf("Successfully bound to port 8080\n");
    return 0;
}