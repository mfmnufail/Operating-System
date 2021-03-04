#include <pthread.h>
#include <stdio.h>


long glb_var = 0;

void * thread_function1(void * arguments);
void * thread_function2(void * arguments);

pthread_mutex_t Mut1 = PTHREAD_MUTEX_INITIALIZER;

int main(void)
{
	pthread_t tid[2];
	long count = 10000000;
	pthread_create(tid,NULL,thread_function1,(void *)(&count));
	pthread_create(tid+1,NULL,thread_function2,(void *)(&count));
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	
	
	printf("The value of the global variable %ld\n", glb_var);
	
	return(0);
}

void * thread_function1(void * arguments)
{
	long x = *(long *)arguments;
	for(long i=0;i<x;++i)
	{
		pthread_mutex_lock(&Mut1);
		glb_var++;
		pthread_mutex_unlock(&Mut1);
	}
	
	pthread_exit(NULL);
	
	
	
}

void * thread_function2(void * arguments)
{
	long x = *(long *)arguments;
	for(long i=0;i<x;++i)
	{
		pthread_mutex_lock(&Mut1);
		glb_var--;
		pthread_mutex_unlock(&Mut1);
	}
	
	pthread_exit(NULL);
	
	
	
}



