#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
 	int clientSocket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr;
	char buffer[1024];
	
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=3003;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	connect(clientSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	printf("Enter Data to be Sent:");
	scanf("%s",buffer);
	send(clientSocket,buffer,1024,0);
}

