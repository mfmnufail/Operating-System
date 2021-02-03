#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main (void)
{
 	int size;
 	printf("Enter the size of your name:");
 	scanf("%d", &size);
 	char name[size];
 	printf("Enter your name:");
 	scanf("%s", name);
 	
 	char age[2];
 	printf("Enter your age:");
 	scanf("%s", age);
 	
 	
 	FILE * fp1 = fopen("./Doc.txt","w+");
 	if(fp1 == NULL)
 	{
 		printf("\nDoc1 could not be opened");
 		perror("\nDoc1.txt");
 		printf("\nThe error number is %d", errno);
 		exit(0);
 	
 	
 	
 	}else{
 		printf("File opened successfully");
 		int bytes_written = fprintf(fp1, "My name is %s my age is %s", name,age);	
 		if(bytes_written == -1)
 		{
 			printf("\nDoc1 could not be written");
	 		perror("\nDoc1.txt");
	 		printf("\nThe error number is %d", errno);
 			exit(0);
 		}else{
			printf("Written to file successfully");
 			fclose(fp1);
 		}
 	
 	}
 	


	return (0);
}
