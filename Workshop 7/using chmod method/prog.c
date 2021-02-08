#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	chmod("./doc3.txt",S_IRWXU | S_IRWXG| S_IRWXO);

	int fd1 = open("./doc3.txt",O_RDWR|O_CREAT|O_APPEND, 0666 );

	if(fd1 == 1)
	{
		perror("doc3.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}

	else 
	{
	printf("\n DOC3 opened successfully ");
	close(fd1);
	chmod("./doc3.txt" ,S_IRUSR | S_IRGRP| S_IROTH);

	
		int fd2 = open("./doc3.txt",S_IRUSR | S_IRGRP| S_IROTH);

		
		if(fd2 == -1)
		{
		perror("doc2.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
		}
		else
		{
			printf("\n Doc2.txt opened sucessfully");
			char buf1[6] = "Nufail";
			
			int bytes_written2 = write(fd2, (void *)buf1, 6);

			if(bytes_written2 == -1)
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
	
	return(0);
}

























