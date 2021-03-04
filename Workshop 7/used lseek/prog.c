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
	
	
	char buf1[16];
	lseek(fd1,14 ,SEEK_SET); 
	int bytes_read = read(fd1, (void *)buf1, 16); //THE FILE OFFSET WILL BE 31
	lseek(fd1,9,SEEK_CUR);
	char buf2[11];
	int bytes_read2 = read(fd1, (void *)buf2, 11); //file offset will be now 51

	
	
	if(bytes_read2 == -1)
	{
		perror("doc1.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
	}
	else{
		printf("wiritten to file successfully");
		close(fd1);
		int fd2 = open("./doc2.txt",O_RDWR|O_CREAT|O_TRUNC,S_IWUSR|S_IRUSR);

		
		if(fd2 == -1)
		{
		perror("doc2.txt");
		printf("File could not be opened properly. Error number %d", errno);
		exit(0);
		}
		else
		{
			printf("\n Doc2.txt opened sucessfully");
			int bytes_written1 = write(fd2, (void *)buf1, 16);
			int bytes_written2 = write(fd2, (void *)buf2, 11);

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
	
	
	}
	
	return(0);
}

























