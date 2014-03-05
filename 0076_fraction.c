#include<stdio.h>
struct fract{
	int num;
	int den;
};
typedef struct fract f;
int lcm(int a,int b)
{
	int i=2,aOrig;
	if(a<b){
		a=a+b-(b=a);
	}
	aOrig=a;
	while(a%b)a=aOrig*i++;
	return a;
}
int gcd(int a,int b)
{
	return ((a*b)/lcm(a,b));
}
int main()
{
	f a,b,c;
	char op;
	scanf("%d/%d",&a.num,&a.den);
	scanf("%c",&op);
	scanf("%d/%d",&b.num,&b.den);
	int l=lcm(a.den,b.den),g;
	switch(op)
	{
		case '+':
			c.num=(a.num*(l/a.den))+(b.num*(l/b.den));
			c.den=l;
			g=gcd(c.num,c.den);
			c.num/=g;
			c.den/=g;
			break;
		case '-':
			c.num=(a.num*(l/a.den))-(b.num*(l/b.den));
			c.den=l;
			g=gcd(c.num,c.den);
			c.num/=g;
			c.den/=g;
			break;
		case '*':
			c.num=(a.num*b.num);
			c.den=(a.den*b.den);
			g=gcd(c.num,c.den);
			c.num/=g;
			c.den/=g;
			break;
		case '/':
			c.num=(a.num*b.den);
			c.den=(a.den*b.num);
			g=gcd(c.num,c.den);
			c.num/=g;
			c.den/=g;
			break;
	}
	printf("%d/%d",c.num,c.den);
	return 0;
}

