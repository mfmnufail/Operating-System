#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int size;
	printf("Enter the size of your name");
	scanf("%d", &size);
	char name[size];

	printf("\n Enter the size of your name");
	scanf("%s", name);
	
	char age[2];
	printf("\n Enter your age");
	scanf("%s", age);

	int fd1 = open("./doc1.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU|S_IRWXG|S_IRWXO );

	if(fd1 == 1)
	{
		perror("doc1.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}

	else 
	{
	printf("\n File opened successfully ");
	int bytes_written1 = write(fd1, (void *)name,size);
	
	char buf1[6] = "age is";
	int bytes_written2 = write(fd1, (void *)buf1, 6);

	int bytes_written3 = write(fd1, (void *)age, 2);
	
	if(bytes_written3 == -1)
	{
		perror("doc1.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}
	else{
		printf("wiritten to file successfully");
		close(fd1);
	}
	
	
	}
	
	return(0);
}

























