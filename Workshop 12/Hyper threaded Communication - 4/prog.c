#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


//long glb_var = 0;

void * thread_function(void * arguments);

struct arguments
{
	int count;
	int ret_value;
	char text[10];
	
};


struct arguments create_arguments(int x, int y, char * z);

int main(void)
{
	char * msg[5] = {"Thread1", "Thread2","Thread3","Thread4","Thread5"};
	pthread_t tid[5];
	
	int count[5] = {1, 3, 4, 5, 3};
	struct arguments args[5];
	void * pt[5];
	
	for(int i=0;i<5;i++)
	{
		args[i] = create_arguments(count[i],(i+1)*10, msg[i]);
		pthread_create(tid+i,NULL,thread_function,(void *)(args+i));
	}

	for(int i=0;i<5;i++)
	{
		pthread_join(tid[i],pt+i);
		printf("\n T%d: Thread_ID is %ld and returning value of %d ",(i+1),tid[i],*(int *)pt[i]);
		
	}
	
	return(0);
}

void * thread_function(void * arguments)
{
	struct arguments arg =  *(struct arguments *)arguments;
	
	int count = arg.count;
	int * returning_value = (int *)malloc(sizeof(int));
	*returning_value = arg.ret_value;
	
	for(int i=0;i<count;++i)
	{
		printf("\n %s", arg.text);
		sleep(0.001);
	}
	
	pthread_exit((void *)returning_value);
	
}

struct arguments create_arguments(int x, int y, char * z)
{
	struct arguments new_arg;
	new_arg.count = x;
	new_arg.ret_value = y;
	stpcpy(new_arg.text, z);
	return new_arg;
}











































