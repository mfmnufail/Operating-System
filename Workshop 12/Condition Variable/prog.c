#include <pthread.h>
#include <stdio.h>


long glb_var = 0;

void * thread_function1(void * arguments);
void * thread_function2(void * arguments);

pthread_mutex_t Mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; //thread1 has finished writing 10 times
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER; //thread2 has finished writing 5 times

int main(void)
{
	pthread_t tid[2];
	int times1 = 10;
	int times2 = 5;
	pthread_create(tid,NULL,thread_function1,(void *)(&times1));
	pthread_create(tid+1,NULL,thread_function2,(void *)(&times2));
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	
	
	printf("The value of the global variable %ld\n", glb_var);
	
	return(0);
}


void * thread_function1(void * arguments)
{
	int times = *(int *)arguments;
	for(int j=0;j<2;j++)
	{
		pthread_mutex_lock(&Mut1);
		
		if(j != 0){pthread_cond_wait(&cond2,&Mut1);}
			for(long i=0;i<times;++i)
			{
				
				printf("\n Thread1");
				
			}
			pthread_mutex_unlock(&Mut1);
			pthread_cond_signal(&cond1);
	}
	
	pthread_exit(NULL);
	
	
	
}

void * thread_function2(void * arguments)
{
	int times = *(int *)arguments;
	for(int j=0;j<6;j++)
	{
		pthread_mutex_lock(&Mut1);
		
		if(j < 3){pthread_cond_wait(&cond1,&Mut1);}
			for(long i=0;i<times;++i)
			{
				
				printf("\n Thread2");
				
			}
			pthread_mutex_unlock(&Mut1);
			pthread_cond_signal(&cond2);
	}
	
	pthread_exit(NULL);
	
	
	
}



