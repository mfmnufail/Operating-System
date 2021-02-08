#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>


int global_initilized_data = 100;

int main(void)
{
	
	static int static_initialized_data = 1000;
	char static static_uninitialized_data[4] ;
	int stack_virtual = 10000; // this will be stored in stack
	
	int * heap_virtual = (int *)malloc(4); // memory casting
	
	(*heap_virtual) = 100000;
	
	pid_t PID = fork();
	
	switch(PID)
	{
		//Error
		case(-1):
		{
			printf("\nThe process could be created!!!");
			perror("\nProcess");
			printf("\n The error number is %d", errno);
			exit(0);
			break;
		}
		//child process
		case(0):
		{
			(*heap_virtual) = 200000;
			stack_virtual = 20000;
			static_initialized_data = 2000;
			global_initilized_data = 200;
			pid_t pid_child = getpid();
			printf("\nchild: with process ID %d, having global_initilized_data= %d, static_initialized_data = %d,static_uninitialized_data = %s, stack_virtual = %d, heap_virtual = %d", pid_child,global_initilized_data,static_initialized_data,static_uninitialized_data,stack_virtual,(*heap_virtual));
			printf("The End of Child");
			break;
		}
		//parent process
		default:
		{
			
			
			printf("\nParent: with process ID %d, having global_initilized_data= %d, static_initialized_data = %d, static_uninitialized_data = %s, stack_virtual = %d, heap_virtual = %d", getpid(),global_initilized_data,static_initialized_data,static_uninitialized_data,stack_virtual,(*heap_virtual));
			sleep(0.01); //10mS
			printf("The end of parent");
			
			
			break;
		}
	}
	
	
	return(0);
}


//global_uninitialized_data = %d,