#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	int FID[2];
	int x = pipe(FID);
	
	if(x == -1)
	{
		printf("\nThe pipe creation is failled");
		perror("\nPipe: ");
		printf("\nErro number is %d", errno);
		
	}else if(x == 0){
		
		printf("\n The parent pipe created successfully");
		int PID = fork();
		
		switch(PID)
		{
			case -1:
			{
				printf("\n Process could not be created");
				perror("\n Process: ");
				printf("\n Erro number is %d", errno);
			
				break;
			}
			
			// child process
			case 0:
			{
				
				char msg_rcv1[20];
				int bytes_read = read(FID[0],(void *)msg_rcv1, sizeof(msg_rcv1));
				
					if(bytes_read==-1)
				{
					printf("\n The reading from pipe is failled");
					perror("\n Chid: ");
					printf("\n Erro number is %d", errno);
					
				}else{
					printf("\n child: The reading from the pipe is success");	
					printf("\n child: The message received from parent is: %s", msg_rcv1);
					
					char msg_snd2[40] = "Child: Hi parent I received the message";
					int bytes_written = write(FID[1],(void *)msg_snd2,sizeof(msg_snd2));
					
					if(bytes_written==-1)
					{
						printf("\n child: The writing to the pipe is failled");
						perror("\n Child: ");
						printf("\n Erro number is %d", errno);
						exit(0);
						
					}else{
					printf("\n Child: The writing to the pipe is success");	
					printf("\n child: Exiting \n");
					exit(0);	
					}
					
				}
				
				
				break;
			}
			
			// Parent process
			default:
			{
				char  msg_snd1[20] = "I am your parent!!!";
				int bytes_written = write(FID[1],(void *)msg_snd1,sizeof(msg_snd1));
				
				if(bytes_written==-1)
				{
					printf("\n The writing to the pipe is failled");
					sleep(0.01);
					perror("\n Parent: ");
					printf("\n Erro number is %d", errno);
					exit(0);
					
				}else{
					printf("\n Parent: The writing to the pipe is success");	
					pid_t PID1 = waitpid(PID,NULL,0);
					
					if(PID1 ==-1)
					{
						printf("\n parent: The waiting failled");
						perror("\n Parent: ");
						printf("\n Erro number is %d", errno);
						
					}else{
						
						printf("\n child exited!");
						
						char msg_rcv2[40];
						
						int bytes_read = read(FID[0],(void *)msg_rcv2,sizeof(msg_rcv2));
						
						if(bytes_read==-1)
						{
							printf("\n parent: The reading from pipe is failled");
							perror("\n Parent: ");
							printf("\n Erro number is %d", errno);
							exit(0);
							
						}else{
							printf("\n Parent: The reading from child is success and the message is: %s", msg_rcv2 );
							printf("\n Parent Exiting!");
							exit(0);
								
						}	
						
						
					}
						
					
				}
				
				break;
			}
			
		}
		
	}
	
	
	return(0);
}