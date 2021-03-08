#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	key_t key1 = ftok("Doc1.txt",23);
	key_t key2 = ftok("Doc1.txt",30);
	
	int SMID1 = shmget(key1,4096,0666|IPC_CREAT);
	int SMID2 = shmget(key2,4096,0666|IPC_CREAT);
	
	pid_t PID1,PID2;
	
	PID1 =  fork();
	
	switch(PID1)
	{
		case -1:
		{
			printf("\nError in ceating process");
			perror("Process 1:");
			printf("Error number is %d", errno);
			exit(0);
			break;
		}
		
		// child C1 and C2
		case 0:
		{
			PID2 = fork();
				switch(PID2)
				{
					case -1:
					{
						printf("\nError in ceating process");
						perror("\nProcess 1:");
						printf("\nError number is %d", errno);
						exit(0);
						break;
					}
					
					// child C2
					case 0:
					{
						sleep(0.01);
						char msg_rcv[30];
						char * shm_addr2 = (char *)shmat(SMID2,NULL, SHM_W|SHM_R);
						strcpy(msg_rcv,shm_addr2);
						printf("\nC2: received %s", msg_rcv);
						
						char msg_snd[30] = "Response from Child C2";
						
						stpcpy(shm_addr2, msg_snd);
						shmdt((void*)shm_addr2);
						exit(0);
					
						break;
					}
					
					//Parent C1
					default:
					{
							sleep(0.0001);
						char msg_rcv1[30];
						char * shm_addr1 = (char *)shmat(SMID1,NULL, SHM_W|SHM_R);
						strcpy(msg_rcv1,shm_addr1);
						printf("\nC1: received %s", msg_rcv1);
						
						char msg_snd1[30] = "Response from Child C1";
						stpcpy(shm_addr1, msg_snd1);
						shmdt((void*)shm_addr1);
						
						char * shm_addr2 = (char *)shmat(SMID2,NULL, SHM_W|SHM_R);
						char msg_snd2[30] = "Message from Parent C1";
						stpcpy(shm_addr2, msg_snd2);
						waitpid(PID2,NULL,0);
						
						char msg_rcv2[30];
			
						strcpy(msg_rcv2,shm_addr2);
						printf("\nC1: received %s", msg_rcv2);
						shmdt((void*)shm_addr2);
						shmctl(SMID2,IPC_RMID,NULL);
						
						exit(0);
						break;
						
					}
		
		
				}
			break;
		}
		
		//Parent P1
		default:
		{
			char msg_snd[30] = "Message from parent P1";
			char * shm_addr1 = (char *)shmat(SMID1,NULL, SHM_W|SHM_R);
			stpcpy(shm_addr1, msg_snd);
			waitpid(PID1,NULL,0);
			char msg_rcv[30];
			strcpy(msg_rcv,shm_addr1);
			printf("\nP1: received %s", msg_rcv);
			shmdt((void*)shm_addr1);
			shmctl(SMID1,IPC_RMID,NULL);
			exit(0);
			break;
			
		}
		
		
	}
	
	
	
	
	return(0);
}