#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	chmod("./Doc1.txt", S_IRWXU|S_IRWXG|S_IRWXO);
	
	FILE * fp1 = fopen("./Doc1.txt", "w+")
	
		if(fp1 == NULL)
		{
			printf("File could not be opened");
			perror("Doc1.txt");
			printf("The error code is %d", errno);
		}else{
			
			printf("File opened successfully");
			fclose(fp1);
			
			chmod("./Doc1.txt", S_RUSR|S_RGRP|S_ROTH);
			
			FILE * fp2 = fopen("./Doc1.txt", "r");
			
		}
	
	
	
	return(0);
}