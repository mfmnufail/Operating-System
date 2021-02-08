#include <stdio.h>
#include <stdlib.h>

double * bubble_sort(double *inputs);
void swap(double *x, double *y);


int main(void)
{
	double inputs[10];
	
	
	for(int i=0; i<10 ; ++i)
	{
	printf("Enter 10 numbers to sort %d",i);
		scanf("%lf", inputs+i);
	}
	
	double *pt = bubble_sort(inputs);
		
	for(int i=0; i<10 ; ++i)
	{
		printf(" %lf \n ", *(pt+i));
	}
	
	
	return (0);
}

double * bubble_sort(double *inputs)
{
	for(int i=0; i<10 ; ++i)
	{
	
	int j = 9;
	while (j>i)
	{
		
		if(*(inputs+i)> *(inputs+j))
		{
			swap((inputs+i),(inputs+j));
		}
		
		--j;
		
		
	}
	
	
	}
	
	return inputs;
	
}

void swap(double *x, double *y)
{
	double temp = *x ;
	*x = *y;
	*y = temp;

}


