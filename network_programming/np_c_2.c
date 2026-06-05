/*

Bind done.
Now it's time for the socket to become-
a passive listener on the port 8080 using listen()

*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); //created the socket
    if(server_fd  == -1){
        perror("Error:");
        exit(1);
    }
    printf("Socket created successfully with file descriptor: %d\n",server_fd);
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = bind(server_fd, (const struct sockaddr *)&address, sizeof(address)); //binding to port 8080
    if(result == -1){
        perror("Bind failed:");
        exit(1);
    }
    printf("Successfully bound to port 8080\n");

    int listen_result = listen(server_fd,5); //Socket is now in a passive listening state. Waiting for connections
    if(listen_result == -1){
        perror("Listen error:");
        exit(1);
    }
    printf("Listening on port 8080\n");
    sleep(30);
    return 0;
}