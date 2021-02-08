#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


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
 	
 	
 	FILE * fp1 = fopen("./Doc.txt","r");
 	if(fp1 == NULL)
 	{
 		printf("\nDoc1 could not be opened");
 		perror("\nDoc1.txt");
 		printf("\nThe error number is %d", errno);
 		exit(0);
 	
 	
 	
 	}else{
 		printf("Doc1 opened successfully");
 		char buf1[9] ;
 		FILE * fp2 = fopen("./Doc2.txt","w");
 			
 		if(fp2 == NULL)
 		{
 		
	 		printf("\nDoc2 could not be opened");
	 		perror("\nDoc2.txt");
	 		printf("\nThe error number is %d", errno);
	 		exit(0);
	 	
 		
 		}
 		else
 		{	
 			printf("Doc2 was opened successfully");
 			while(EOF != fscanf(fp1,"%s", buf1))
	 		{
	 		
		 		int bytes_written = fprintf(fp2, " %s ", buf1);	
		 		if(bytes_written == -1)
		 		{
		 			printf("\nDoc1 could not be written");
			 		perror("\nDoc1.txt");
			 		printf("\nThe error number is %d", errno);
		 			exit(0);
	 			}
	 			
	 		}
	 		
			printf("Written to Doc2 successfully");
	 		fclose(fp1);
	 		fclose(fp2);
 		
 		
 		}
	 		
 		
 	
 	}
 	


	return (0);
}
