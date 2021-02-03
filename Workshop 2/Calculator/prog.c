#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculator(char *operation, double *num1, double *num2);

int main (void)
{

	char operation;
	double num1, num2;

	printf("Enter calculator operation");
	scanf("%c" , &operation);
		printf("Enter first value");
	scanf("%lf" , &num1);
		printf("Enter second value");
	scanf("%lf" , &num2);
	
	double num = calculator(&operation, &num1, &num2);
	printf("%lf", num);
	
}

double calculator(char *operation, double *num1, double *num2)
{
	switch(*operation)
	{
		case '+':
		return *num1 + *num2;
		break;
	
		case '-':
		return *num1 - *num2;
		break;
	
		case '*':
		return *num1 * *num2;
		break;
	
		case '/':
		return *num1 / *num2;
		break;
		
		default:
		printf("Invalid input");
	}


}
