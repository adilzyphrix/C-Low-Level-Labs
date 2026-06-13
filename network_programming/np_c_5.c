/*

A Client Program that sucessfully connects
to a Server Program(np_c_4.c)

Open two different terminals and run both the programs.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main()
{
    int client_fd = socket(AF_INET,SOCK_STREAM,0);
    if(client_fd == -1){
        perror("Error");
        exit(1);
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_port = htons(8080);
    server_address.sin_family = AF_INET;
    if(inet_pton(AF_INET,"127.0.0.1",&server_address.sin_addr) <= 0){ //inet_pton() returns 0 and -1 in case of Error
        perror("Error");
        exit(1);
    }

    int result = connect(client_fd,(const struct sockaddr *)&server_address,sizeof(server_address)); //Client initiates the connection via TCP 3-Way handshake
    if(result == 0)
        printf("TCP 3-Way handshaking successfull\nConnected to the server\n");
    else{
        perror("Error");
        exit(1);
    }
    close(client_fd);
    return 0;
}