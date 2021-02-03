#include <stdio.h>
#include <stdlib.h>


struct person_struct
{
	double weight;
	int age;
	double height;
};

union person_union
{
	double weight;
	int age;
	double height;
	
};


int main()
{
	
	struct person_struct ins1 ;
	union person_union ins2 ;
	
	
	printf(" \n Enter your weight: ");
	scanf("%lf", &(ins1.weight));
	ins2.weight = ins1.weight;
	
	printf(" \n Enter your height: ");
	scanf("%lf", &(ins1.height));
	ins2.height = ins1.height;
	
		printf(" \n Enter your age: ");
	scanf("%d", &ins1.age);
	ins2.age = ins1.age;


	printf("Your weight %lf, height %lf, age %d \n", ins1.weight, ins1.height,ins1.age);
	printf("Your weight %lf, height %lf, age %d", ins2.weight, ins2.height,ins2.age);
	
	
	return (0);
}


