#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	printf("Enter your name size:");
	int size;
	scanf("%d", &size);
	char name[size];
	printf("Enter your name:");
	scanf("%s",name);
	char age[2];
	printf("\nEnter your age:");
	scanf("%s", age);
	
	FILE * fp1 = fopen("./Doc1.txt","w+");
	
	if(fp1 == NULL)
	{
		printf("\nDoc1 open failed");
		perror("\nDoc1.txt");
		printf("\n The error number is %d", errno);
		exit(0);
		
	}else{
		printf("Doc1 opened successfully!!!\n");
		int fd1 = fprintf(fp1, "Hi Iam %s and I am %s years old",name,age);
		
		if(fd1 == -1)
		{
			printf("Doc1 open failed");
			perror("./Doc1.txt");
			printf("%d", errno);
		}
		
		printf("write successfully to Doc1");
		fclose(fp1);
	}
	
	return(0);
}