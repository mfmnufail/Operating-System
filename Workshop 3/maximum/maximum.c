#include <stdio.h>
#include <stdlib.h>

double maximum(double *inputs);

int main()
{
	double intputs[10];
	
	for(int i=0; i<10; ++i)
	{	printf ("Enter number %lf", i);
		scanf("%lf", (inputs+i));
		
	}
	printf("The maximum number %lf", maximum(inputs));
	

}

double maximum(double *inputs)
{
	double max = *inputs
	int i  = 1;
	while(i<10)
	{
		if (*(input+i)>max)
		{
		max = inputs+i;
		}
		
	++i;
	}
	
	return max

}

