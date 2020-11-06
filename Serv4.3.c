#include<stdio.h>
#include<string.h>      //strlen
#include<sys/socket.h>
#include<netdb.h> //hostent
#include<unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include<arpa/inet.h>   //inet_addr

int main(int argc , char *argv[])
{
        int socket_desc, new_socket, c;
        struct sockaddr_in server, client;
        char *message;
        int optval;
        socklen_t optlen = sizeof(optval);

        //Create socket
        socket_desc = socket(AF_INET,SOCK_STREAM,0);
        if(socket_desc == -1)
        {
                printf("Could not create socket");
        }




        /* Check  the status fro the keepalive option */
        if(getsockopt(socket_desc, SOL_SOCKET,SO_KEEPALIVE, &optval, & optlen)<$
	{
	perror("getsockopt()");
        close(socket_desc);
        exit(EXIT_FAILURE);
        }
        printf("SO_KEEPALIVE is %s\n",(optval ? "ON" : "OFF"));

        //Set the option active
        optval=1;
        optlen=sizeof(optval);
        if(setsockopt(socket_desc,SOL_SOCKET,SO_KEEPALIVE,&optval,optlen)<0){
                perror("setsockopt()");
                close(socket_desc);
                exit(EXIT_FAILURE);
        }

        printf("SO_KEEPALIVE set on socket\n");

        //Check status again
        if(getsockopt(socket_desc, SOL_SOCKET,SO_KEEPALIVE,&optval,&optlen)<0){	
        perror("getsockopt()");
        close(socket_desc);
        exit(EXIT_FAILURE);
        }
        printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));
   close(socket_desc);

   exit(EXIT_SUCCESS);
}
	

