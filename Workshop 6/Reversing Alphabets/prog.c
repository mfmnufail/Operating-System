#include <stdio.h>
#include <stdlib.h>

//char name_divider(char name);

int main()
{

	char **  inputs[4][6];
	
	printf("Enter 4 name with 6 letters: ");
	
	for(int i=0 ; i<4 ; ++i)
	{
	
		scanf("%c", *inputs[i]);

		
	}
	
	for(int i=0 ; i<4 ; ++i)
	{
	  for(int j=0 ; j<6 ; ++j)
	{
		printf("\n %s", inputs[i][j]);

	}	
	}
	
	//name_divider(inputs);
	
	


}


