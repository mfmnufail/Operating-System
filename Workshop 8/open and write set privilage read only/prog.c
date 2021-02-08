#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>


int main (void)
{
 	/*int size;
 	printf("Enter the size of your name:");
 	scanf("%d", &size);
 	char name[size];
 	printf("Enter your name:");
 	scanf("%s", name);
 	
 	char age[2];
 	printf("Enter your age:");
 	scanf("%s", age);*/
 	
 	chmod("./Doc1.txt", S_IRWXU|S_IRWXG|S_IRWXO);
 	FILE * fp1 = fopen("./Doc1.txt","w+");
 	if(fp1 == NULL)
 	{
 		printf("\nDoc1 could not be opened");
 		perror("\nDoc1.txt");
 		printf("\nThe error number is %d", errno);
 		exit(0);
 	
 	
 	
 	}else{
 		printf("Doc1 opened successfully");
 		fclose(fp1);
 		chmod("./Doc1.txt", S_IRUSR|S_IRGRP|S_IROTH);
 		
 		FILE * fp2 = fopen("./Doc1.txt","r");
 			
 		if(fp2 == NULL)
 		{
 		
	 		printf("\nDoc1 could not be opened");
	 		perror("\nDoc1.txt");
	 		printf("\nThe error number is %d", errno);
	 		exit(0);
	 	
 		
 		}
 		else
 		{	
	 		printf("Doc1 opened successfully");
			int bytes_written = fprintf(fp2, " %s ","A sentense");	
	 		if(bytes_written == -1)
		 		{
			 			printf("\nDoc1 could not be written");
				 		perror("\nDoc1.txt");
				 		printf("\nThe error number is %d", errno);
			 			exit(0);
		 		}
	 			
	 		
	 		
			printf("Written to Doc2 successfully");
	 		
	 		fclose(fp2);
 		
 		
 		}
	 		
 		
 	
 	}
 	


	return (0);
}
