/*

It's time to fetch the IP and Port(using accept() call)
of those clients that completed
the 3-way TCP handshake,
from the accept queue that was
created using listen()

    Compile and run this program
    Then, open a new terminal and use the netcat/nc command
        $ netcat 127.0.0.1 8080
    127.0.0.1 --> loopback address

*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd  == -1){
        perror("Error");
        exit(1);
    }
    printf("Socket created successfully with file descriptor: %d\n",server_fd);
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = bind(server_fd, (const struct sockaddr *)&address, sizeof(address));
    if(result == -1){
        perror("Bind failed");
        exit(1);
    }
    printf("Successfully bound to port 8080\n");

    int listen_result = listen(server_fd,5);
    if(listen_result == -1){
        perror("Listen error");
        exit(1);
    }
    printf("Listening on port 8080\n");
    
    struct sockaddr_in client_addr; // empty structure to store the client's IP and Port
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd,(struct sockaddr *)&client_addr, &client_len); //pass NULL to 2nd and 3rd parameters if you don't care about who's connecting with the server
    if(client_fd == -1){
        perror("Error");
        exit(1);
    }
    printf("Client connected. New client file descriptor = %d\n",client_fd); // This new file descriptor will be used to communicate with this particular client
    close(client_fd);
    close(server_fd);
    return 0;
}