#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculator(double *radius, double *height);

int main(void)
{
	double radius, height;
	
	printf("Enter Cylinder Radius: ");
	scanf("%lf", &radius);
	
	printf("Enter Cylinder Height: ");
	scanf("%lf", &height);
	
	double volume =  calculator(&radius, &height);
	printf("The volume of the cylinder %lf", volume);
	
}

double calculator(double *radius, double *height)
{
	return M_PI * (*radius) * (*radius) * (*height);
}

