#include<stdio.h>
inline int read()
{
	char c;
	int n=0;
	while((c=getchar_unlocked())<'0');
	n+=(c-'0');
	while((c=getchar_unlocked())>='0')
		n=n*10+(c-'0');
	return n;
}
int main()
{
	int n,x1,y1,x2,y2,x3,y3,A,B,C,c=0;
	n=read();
	while(n--)
	{
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		x3=read();
		y3=read();
		A=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		B=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
		C=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
		if(A==(B+C)||B==(C+A)||C==(A+B))
			c++;
	}
	printf("%d\n",c);
	return 0;
}
