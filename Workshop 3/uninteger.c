#include <stdio.h>
#include <stdlib.h>

 long int factorial( int *num);


int main()
{
	int num;
	printf("Enter an integer \n");
	scanf("%d", &num);
	printf("The factorial of the number is %lu \n", factorial(&num) );
	

}

long int factorial(int *num)
{
	int temp = (*num) -1;
	
	return (*num) * (factorial(&temp));

}
