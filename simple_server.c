#include <stdio.h>                                                                        //Network sockets have two major types. Stream Sockets and Datagram sockets. The stream socket
#include <stdlib.h>                                                                       //is commonly used in the TCP/IP protocol family. It is a two way hand shack where both ends
#include <string.h>                                                                       //need to have a connection to ensure communications. The datagram socket is a one way type
#include <sys/socket.h>                                                                   //connection that is much faster. However, it is not very relyable. The most common place to
#include <netinet/in.h>                                                                   //find these types of sockets is in the online gaming world.
#include <arpa/inet.h>                                                                    //Sockets have multiple functions. In order to create a socket we use the socket() function.
#include "hacking.h"                                                                      //Once the socket is created the function returns a file descriptor (fd) that can be saved as
                                                                                          //an integer value. The function connect() will connect the socket, based on the fd, to the 
#define PORT 7890 //Port users connect to                                                 //remote host. In order for a socket to be able to listen for incoming connection it must be
                                                                                          //bound to the local host using the bind() function. For a socket to not only listen for a 
int main(void)                                                                            //connection but also queu the connection requests up to backlog_queue_size it must use the
{                                                                                         //listen() function. In order to accept an incoming connection on a bound socket, and to put
  int sockfd, new_sockfd; //Listen on sockfd, new connection on new_fd                    //that information into the remote_host structure, also the actuall size of the address struct
  struct sockaddr_in host_addr, client_addr; //My address information                     //being written to *addr_length, we use the accept() function. The send() function sends out n
  socklen_t sin_size;                                                                     //bytes from *buffer to socket fd. The recv() function recieves n bytes from socket fd into
  int recv_length = 1, yes = 1;                                                           //*buffer.
  char buffer[1024];                                                                      //
  //                  TCP/IP   stream socket                                              //
  if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)                                    //
    fatal("in socket");                                                                   //
                                                                                          //
  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)               //
    fatal("setting socket option SO_REUSEADDR");                                          //
  //Setting up the host address structure for the bind and listen calls                   //
  host_addr.sin_family = AF_INET; //Host Byte order                                       //
  host_addr.sin_port = htons(PORT); //Short, net byte order                               //
  host_addr.sin_addr.s_addr = 0; //Auto fill with my IP                                   //
  memset(&(host_addr.sin_zero), "\0", 8); //Zero the rest of the struct                   //
                                                                                          //
  if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)          //
    fatal("binding to socket");                                                           //
                                                                                          //
  if(listen(sockfd, 5) == -1)                                                             //
    fatal("listening on socket");                                                         //

  char user_input[2048];
  
  //The accept loop
  while(1){
    sin_size = sizeof(struct sockaddr_in);
    new_sockfd = accept(sockfd, (struct sockadder *)&client_addr, &sin_size);
    if(new_sockfd == -1)
      fatal("accepting connection");
    printf("server: got connection from %s port %d\n",
	   inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    send(new_sockfd, "hello world!\n", 13, 0);
    recv_length = recv(new_sockfd, &buffer, 1024, 0);
    while(recv_length > 0){
      printf("RECV: %d bytes\n", recv_length);
      dump(buffer, recv_length);
      recv_length = recv(new_sockfd, &buffer, 1024, 0);
    }
    close(new_sockfd);
  }
  return 0;
}
