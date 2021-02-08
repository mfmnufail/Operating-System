#include <stdio.h>
#include <stdlib.h>

long unsigned int calculator(long int *num);

int main(void)
{
  long int num;
  printf("Enter a number to calculate factorial ");
  scanf("%ld", &num);
  printf("The value: %lu",calculator(&num));
  return (0);

}


long unsigned int calculator(long int *num)
{
	if(*num < 0)
	{
		printf("No factorial for minus values ");
		exit(0);
	}
	
	else if( *num==0)
	{
		return 1;
	}
	
	else if(*num == 35){
		printf("The number is very large");
		exit(0);
	}
	else 
	{
		long int temp = (*num)-1;
		return( (*num) * calculator(&temp));
	}

}
