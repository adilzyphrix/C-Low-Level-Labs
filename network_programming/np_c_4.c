/*

A Server Program that sucessfully connects
to a Client Program(np_c_5.c)

Open two different terminals and run both the programs.

*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); //socket created
    if(server_fd  == -1){
        perror("Error");
        exit(1);
    }
    printf("Socket created successfully with file descriptor: %d\n",server_fd);
    
    struct sockaddr_in address = {0}; //initialised the entire array as 0 so that the char zer0[8] also becomes zero although it is not needed
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = bind(server_fd, (const struct sockaddr *)&address, sizeof(address)); //socket bound
    if(result == -1){
        perror("Bind failed");
        exit(1);
    }
    printf("Successfully bound to port 8080\n");

    int listen_result = listen(server_fd,5); //transitioning from an active state to passive listening state
    if(listen_result == -1){
        perror("Listen error");
        exit(1);
    }
    printf("Listening on port 8080\n");
    
    struct sockaddr_in client_addr; //empty struct created for storing CLient's socket address
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd,(struct sockaddr *)&client_addr, &client_len); //accept() syscall used to connect to the client socket. Returns a new file descriptor
    if(client_fd == -1){
        perror("Error");
        exit(1);
    }
    printf("Client connected. New client file descriptor = %d\n",client_fd);
    close(client_fd);
    close(server_fd);
    return 0;
}