#include <stdio.h> // standard input and output
#include <stdlib.h> // exit(0), process, heap memory allocation malloc()
#include <unistd.h> // File discriptors, process identifiers. Pipe calls pipe()
#include <sys/types.h> // getpid() and getppid() functions , fork()
#include <errno.h> // For error number retrival
#include <sys/wait.h> // parent process to wait for the child execution waitpid()

int main(void){
	
	int FD[2]; // creating file discriptor for reading and writing to the pipe
	int x= pipe(FD); // para: memory location of file discriptor 
	
	if(x == -1){ // pipe creation failed
		
		// error hanlding
		
	}else if ( x == 0){
		
		pid_t PID1 = fork(); // creating a child process
	
	
		switch(PID1){
			
			case(-1):
			{
				// error handling
				perror("Process");
				break;
			}
			case(0):{
				// child process
				printf("Child created successfully\n");
				sleep(0.01); // suspend for 10ms to parent execution 
				
				printf("Child awake successfully\n");
				char msg_rcv[20];
				int byttes_read = read(FD[0],(void *)msg_rcv, 20);
				
				if(byttes_read == -1){
					// error hanling for byttes_read
					
				}else{
					printf("\n Child read successfully\n");
					printf("The read message is : %s", msg_rcv);
					printf("Child exiting ");
					exit(0);
				}
				
			}
			
			default:{
				// parent process
				
				printf("Parent created successfully\n");
				char msg_snd[20] = "Hi, Parent: msg sent";
				int byttes_written = write(FD[1], (void *)msg_snd, 20);
				
				if(byttes_written == -1){
					
					// error handling for write 
					
				}else{
					printf("Written to pipe successfully\n");
					pid_t pid = waitpid(PID1,NULL,0);
					
					if(pid == -1){
						// error handling for waiting 
						
					}else{
						
						printf("Exiting parent \n");
						
					}
				}
				
				
		
			}
			
		}
	
		
		
		
	}
	
	
	
	return(0);
}