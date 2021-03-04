#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	FILE * fp1 = fopen("./Doc1.txt", "r");
	
	if(fp1 == NULL)
	{
		printf("The DOC1 could not open");
		perror("DOC1.txt");
		printf("%d", errno);
		exit(0);
	}else{
		
		printf("File opened successfully");
		char buffer[7];
		FILE * fp2 = fopen("./Doc2.txt", "w");
		
		if(fp2 == NULL)
 		{
 		
	 		printf("\nDoc2 could not be opened");
	 		perror("\nDoc2.txt");
	 		printf("\nThe error number is %d", errno);
	 		exit(0);
	 	
 		
 		}else{
		
			printf("Doc2 is opened successfully");
			while(EOF != fscanf(fp1,"%s", buffer) )
			{
				int bytes_written = fprintf(fp2, "%s ", buffer);
				
				if(bytes_written == -1)
				{
					printf("The DOC1 could not written to Doc2");
					perror("DOC1.txt");
					printf("%d", errno);
					exit(0);
					
				}
				
			}
		
		printf("The DOC1 successfully copied to Doc2");
		fclose(fp1);
		fclose(fp2);
		
		}
	}
	
	
	
	return(0);
}