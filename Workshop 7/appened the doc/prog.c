#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	

	int fd1 = open("./doc1.txt",O_RDONLY|O_CREAT|O_APPEND, 0666 );

	if(fd1 == 1)
	{
		perror("doc1.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}

	else 
	{
	printf("\n File opened successfully ");
	
	
	char buf1[8]; 
	int bytes_read = read(fd1, (void *)buf1, 8);

	
	
	if(bytes_read == -1)
	{
		perror("doc1.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}
	else{
		printf("wiritten to file successfully");
		close(fd1);
		int fd2 = open("./doc2.txt",O_RDWR|O_CREAT|O_TRUNC,S_IWUSR|S_IRUSR);

		
		if(fd1 == -1)
		{
		perror("doc2.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
		}
		else
		{
			printf("\n Doc2.txt opened sucessfully");
			int bytes_written = write(fd2, (void *)buf1, 18);

			if(bytes_written == -1)
			{
			perror("doc2.txt");
			printf("File could not be opened properly. Error number %d", errno);
			exit(0);
			}
			else
			{
				printf("\n Doc2.txt opened sucessfully");
				close(fd2);
			}
		}
	}
	
	
	}
	
	return(0);
}

























