//Good ol' scanf and printf; also need this to handle file IO
#include <stdio.h>
//lol @ library full of std
#include <stdlib.h>
//Going to need this for time(), ctime() - which are in turn needed for tick management
#include <time.h>
//For IP addresses and ports
#include <netinet/in.h>
//***I need to learn what this does
#include <arpa/inet.h>
//Makes available functions connect(), socket(), bind(), listen(), accept()
#include <sys/socket.h>
//Makes available all kinds of useful datatypes.  Here we will use time_t, off_t
#include <sys/types.h>
//I need NULL, and might be a dependency for other includes.
//I'll need to try removing this at different stages in implementation and see what it breaks :x
#include <unistd.h>
//I can handle errors in a nicely human-readable way by strerr(errno)
#include <errno.h>
//So I don't have to manually duct tape char into string-like functionality
#include <string.h>

//since I need to enter command line arguments to set server IP
int main(int argc, char *argv[])
{
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;
	char sendBuffer[1024];
	time_t ticks;

//lets begin by creating the socket
	listenfd = socket(AF_INET , SOCK_STREAM , 0);
	if (listenfd == -1)
	{
		printf("Error:  Socket creation failed!!\n");
	}
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuffer, '0', sizeof(sendBuffer));

//bind socket to server
	//svr socket address internet family is set to address family internetwork (UDP,TCP,etc.)
	serv_addr.sin_family = AF_INET;
	//svr socket internet address is set to any host address, in network byte order
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//svr socket address internet port is set to port 5000 in network byte order
	serv_addr.sin_port = htons(5000);

//lets begin listening for connections
	//give the value stored in the structure given by serv_addr to the socket
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	//listen on socket for up to 2 client connections
	listen(listenfd, 2);

//ok, lets establish a connection
	while(1)
	{
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
//lets stream some data
	//take input from stream	
	//write input to file
//time to close the connection
		close(connfd);
		sleep(1);
	}






return 0;
}
