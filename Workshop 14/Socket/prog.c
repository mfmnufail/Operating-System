#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <wait.h>


int main(void)
{
	int sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	struct sockaddr_in inst;
	inst.sin_family = AF_INET;
	inst.sin_port = htons(7);
	char net_addr [] = "173.12.34.20";
	inet_aton(net_addr,&inst.sin_addr );
	memset((void *)inst.sin_zero,'0',sizeof(inst));
	
	int x = connect(sock_fd,(struct sockaddr *)&inst, sizeof(&inst));
	
	if(x == -1)
	{
		printf("Error in connecting");
		perror("connect:");
		exit(0);
		
	}else{
		
		printf("\n Connection established successfully");
		int size;
		printf("\n Enter size: ");
		scanf("%d", &size);
		char buf[size];
		
		printf("\n Enter Message: ");
		scanf("%s", buf);
		
		int y = write(sock_fd,(void *)buf,size);
		
		if(y == -1)
		{
			printf("Error in writing");
			perror("Write:");
			exit(0);
			
		}else{
			
			printf("\n Written to socket successfully. Waiting for reply");
			sleep(2);
			char buf2[size];
			int z = read(sock_fd,(void *)buf2,size);
			
			if(z == -1)
			{
				printf("Error in read");
				perror("Read: ");
				exit(0);
				
			}else{
				printf("\n Received: %s", buf2);
				shutdown(sock_fd,SHUT_RDWR);
				close(sock_fd);
				exit(0);
			}
		}
	}
	
	
	
	return(0);
}