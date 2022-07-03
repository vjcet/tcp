#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int serverSocket,newSocket;
	struct sockaddr_in serverAddr,newAddr;
	
	socklen_t addr_size;
	char buffer[1024];

	serverSocket=socket(AF_INET,SOCK_STREAM,0);

	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=3003;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	bind(serverSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	listen(serverSocket,5);
	printf("listening...\n");
	addr_size=sizeof(newAddr);
	newSocket=accept(serverSocket,(struct sockaddr*)&newAddr,&addr_size);
	

	recv(newSocket,buffer,1024,0);
	printf("DATA RECEVIED:%s",buffer);
}
 
