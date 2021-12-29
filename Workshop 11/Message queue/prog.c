#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/msg.h>
#include <string.h>

struct msg 
{
	long type;
	char text[100];
};

struct msg create_msg(long x, char * y);


int main(void)
{

	pid_t PID1 = fork();
	
	switch(PID1)
	{
		case(-1):
		{
			printf("\nProcess creation is failled");
			perror("Process: ");
			printf("The error number is %d", errno);
			
			break;
		}
		
		// Child C1 and C1
		case(0):
		{
			pid_t PID2 = fork();
			
			switch(PID2)
				{
					case(-1):
					{
						printf("\n Child C2 creation is failled");
						perror("Process: ");
						printf("The error number is %d", errno);
						
						break;
					}
					
					//Child C2
					case(0):
					{
						sleep(0.01);
						key_t key1 = ftok("Doc1.txt",1);
						int MQID = msgget(key1,0);
						
					
							
							struct msg rcv_message2[4];
							
							for(int i=0;i<4; ++i)
							{
								int x = msgrcv(MQID,(void *)(rcv_message2+i),sizeof(rcv_message2[i].text),-300,IPC_NOWAIT);
								
								if(x==-1)
								{
									printf("\n Parent C2: Message sending is failled");
									perror("\nMSGSND: ");
									printf("\nThe error number is %d", errno);
									exit(0);
									
								}
								
							}
							
							printf("\n Child C2: The messages are read successfully\n");
							
							for(int i=0;i<4;++i)
							{
								printf("\nChild C2: The read with process id %id, messages are: %s\n",getpid(), rcv_message2[i].text);
							}
							
							printf("\nThe Child C2 exiting\n");
							exit(0);
						
						
						
						break;
					}
					
					// Child C1
					default:
					{
						sleep(0.0001);
						key_t key1 = ftok("Doc1.txt",1);
						int MQID  = msgget(key1,0);
			
						
							struct msg rcv_message1[3];
							
							for(int i=0;i<3;++i)
							{
								int x = msgrcv(MQID,(void *)(rcv_message1+i),sizeof(rcv_message1[i].text),0,IPC_NOWAIT);
								
								if(x==-1)
								{
									printf("\n Parent P1: Message sending is failled");
									perror("\nMSGSND: ");
									printf("\nThe error number is %d", errno);
									exit(0);
									
								}
									
							}
							
							printf("\n Child C1: The first three messages read from MQ successfully ");
							for(int i=0;i<3;++i)
							{
								printf("\nChild C1: The read with process id %id, messages are: %s\n",getpid(), rcv_message1[i].text);
							}
							
							waitpid(PID2,NULL,0);
							printf("\n Child c1: Exiting\n");
							exit(0);
						
						
						break;
					}
				}
			
			
			break;
		}
		
		// Parent- Initial Process
		default:
		{
			key_t key1 = ftok("Doc1.txt",1);
			
			int MQID  = msgget(key1,IPC_CREAT|IPC_EXCL|S_IRWXU|S_IRWXG|S_IRWXO);
			
			if(MQID == -1)
			{
				printf("\n Parent P1: Message queue creation is failled");
				perror("MQ: ");
				printf("The error number is %d", errno);
				exit(0);
			}else{
				
				printf("\nParent P1; Message queue created queue");
				char msg1[20] = "First Message";
				char msg2[20] = "Second Message";
				char msg3[20] = "Third Message";
				char msg4[20] = "Fourth Message";
				char msg5[20] = "Fifth Message";
				char msg6[20] = "Sixth Message";
				char msg7[20] = "Seventh Message";
				char msg8[20] = "Eighth Message";
				
				struct msg sending_messages[8];
				
				sending_messages[0] = create_msg(100,msg1);
				sending_messages[1] = create_msg(200,msg2);
				sending_messages[2] = create_msg(300,msg3);
				sending_messages[3] = create_msg(100,msg4);
				sending_messages[4] = create_msg(200,msg5);
				sending_messages[5] = create_msg(100,msg6);
				sending_messages[6] = create_msg(300,msg7);
				sending_messages[7] = create_msg(150,msg8);
				
				for(int i=0; i<8; ++i)
				{
					int x = msgsnd(MQID,(void *)(sending_messages+i),sizeof(sending_messages[i].text),IPC_NOWAIT);
					
					if(x==-1)
					{
						printf("\n Parent P1: Message sending is failled");
						perror("\nMSGSND: ");
						printf("\nThe error number is %d", errno);
						exit(0);
						
					}
					
					
				}
				
				printf("\nParent P1: All messages were sent to the queue successfully\n");
					waitpid(PID1,NULL,0);
					struct msg rcv_message;
					int y = msgrcv(MQID,(void *)(&rcv_message),sizeof(rcv_message.text),300,IPC_NOWAIT);
					
						if(y==-1)
					{
						printf("\n Parent P1: Message reading is failled");
						perror("\nMSGSND: ");
						printf("\nThe error number is %d", errno);
						exit(0);
						
					}else{
						printf("Parent P1: parent process id: %d, read message is %s",getpid(),rcv_message.text);
						printf("Parent P1: parent read from queue from successfully, parent exiting\n  ");
						msgctl(MQID,IPC_RMID,NULL);
						exit(0);
					}
					
			}
			
			
			break;
		}
	}
	
	
	
	return(0);
}


struct msg create_msg(long x, char * y)
{
	struct msg newmsg;
	newmsg.type = x;
	strcpy(newmsg.text,y);
	
	return newmsg;
}



// key_t= ftok() >>> Message Structure with type and text >>> pid_t fork() >>> int MQID = msgget(filtoken,flags)>>> msgsnd(MQID,(void *)address,sizeof(),flag)