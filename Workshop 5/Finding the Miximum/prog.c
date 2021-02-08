#include <stdio.h>
#include <stdlib.h>

double finder(double *inputs);

int main(void)
{
	double inputs[10];
	
	printf("Enter 10 numbers to find maxima:");
	
	for(int i=0; i<10 ; ++i)
	{
		scanf("%lf", inputs+i);
	
	}
	
	double max = finder( inputs);
	printf("Entered Maximum Value: %0.2lf", max);
}

double finder(double *inputs)
{
	double max = *inputs;
	
	for(int i=0 ; i<10 ; ++i)
	{
		if(*(inputs+i)>max)
		{
			max = *(inputs+i);
		}
		
	}
	
	return max;
}
