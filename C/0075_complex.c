#include<stdio.h>
struct cmplx
{
	double real;
	double imaginary;
};
int main()
{
	struct cmplx a,b,c;
	double den;
	printf("Real(A):");
	scanf("%lf",&a.real);
	printf("Imaginary(A):");
	scanf("%lf",&a.imaginary);
	printf("Real(B):");
	scanf("%lf",&b.real);
	printf("Imaginary(B):");
	scanf("%lf",&b.imaginary);
	printf("Sum:\n");
	c.real=a.real+b.real;
	c.imaginary=a.imaginary+b.imaginary;
	if(c.imaginary>=0)
		printf("%lf+%lfi\n",c.real,c.imaginary);
	else if(c.imaginary<0)
		printf("%lf%lfi\n",c.real,c.imaginary);
	c.real=a.real-b.real;
	c.imaginary=a.imaginary-b.imaginary;
	printf("Difference:\n");
	if(c.imaginary>=0)
		printf("%lf+%lfi\n",c.real,c.imaginary);
	else if(c.imaginary<0)
		printf("%lf%lfi\n",c.real,c.imaginary);
	c.real=(a.real*b.real-a.imaginary*b.imaginary);
	c.imaginary=(a.imaginary*b.real+a.real*b.imaginary);
	printf("Product:\n");
	if(c.imaginary>=0)
		printf("%lf+%lfi\n",c.real,c.imaginary);
	else if(c.imaginary<0)
		printf("%lf%lfi\n",c.real,c.imaginary);
	den=a.imaginary*a.imaginary+b.imaginary*b.imaginary;
	c.real=(a.real*b.real+a.imaginary*b.imaginary)/den;
	c.imaginary=(a.imaginary*b.real-a.real*b.imaginary)/den;
	printf("Quotient:\n");
	if(c.imaginary>=0)
		printf("%lf+%lfi\n",c.real,c.imaginary);
	else if(c.imaginary<0)
		printf("%lf%lfi\n",c.real,c.imaginary);
	return 0;
}
