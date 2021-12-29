#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>


long glb_var = 0;

void * thread_function1(void * arguments);
void * thread_function2(void * arguments);
void * thread_function3(void * arguments);

const char * name1 = "name1";
const char * name2 = "name2";
sem_t *sem1;
sem_t *sem2;


int main(void)
{
	pthread_t tid[3];
	char a[] = " My name is ";
	char b[] = "Hello ";
	char c[] = " Nufail";
	
	sem1 = sem_open(name1,O_CREAT|0666,0);
	sem2 = sem_open(name2,O_CREAT|0666,0);
	
	pthread_create(tid,NULL,thread_function1,(void *)(a));
	pthread_create(tid+1,NULL,thread_function2,(void *)(b));
	pthread_create(tid+2,NULL,thread_function2,(void *)(c));
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	
	int * x;
	int * y;
	sem_getvalue(sem1, x);
	sem_getvalue(sem2, y);
	printf("The final value of the semaphores: %d, %d", *x, *y);
	sem_close(sem1);
	sem_close(sem2);
	sem_unlink(name1);
	sem_unlink(name2);
	
	return(0);
}


void * thread_function1(void * arguments)
{
	char *x = (char *)arguments;
	printf("%s", x);
	sem_post(sem1);
	
	pthread_exit(NULL);
}

void * thread_function2(void * arguments)
{
	sem_wait(sem1);
	char *y = (char *)arguments;
	printf("%s", y);
	sem_post(sem2);
	pthread_exit(NULL);
	
	

}

void * thread_function3(void * arguments)
{
	sem_wait(sem2);
	char *z = (char *)arguments;
	printf("%s", z);

	pthread_exit(NULL);
	
	

}




