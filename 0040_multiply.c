#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int my_strlen(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}
void m(char a[],char b[],int flaga,int flagb)
{
	int i,j,k,x,y,lena,lenb,lenP;
	long int r=0;
	long sum=0;
	char c[1400000],temp[1400000],product[1400000];
	k=x=0;
	lena=my_strlen(a);
	lenb=my_strlen(b);
	lena--;
	lenb--;
	for(i=0;i<lena+1;i++)
		a[i]-='0';
	for(i=0;i<lenb+1;i++)
		b[i]-='0';
	for(i=lenb;i>=0;i--)
	{
		r=0;								//r is the carry
		for(j=lena;j>=0;j--)
		{
			temp[k++]=(b[i]*a[j]+r)%10;				//temp stores all intermediate sums
			r=(b[i]*a[j]+r)/10;
		}
		temp[k++]=r;
		x++;
		for(y=0;y<x;y++)
			temp[k++]=0;
	}
	k=0;
	r=0;
	for(i=0;i<lena+lenb+2;i++)
	{
		sum=0;
		y=0;
		for(j=1;j<=lenb+1;j++)
		{
			if(i<=lena+j)
				sum+=temp[y+i];
			y+=j+lena+1;
		}
		c[k++]=(sum+r)%10;						//c is the reversed final product
		r=(sum+r)/10;
	}
	c[k]=r;
	j=0;
	for(i=k-1;i>=0;i--)
		product[j++]=c[i]+'0';
	product[j]='\0';
	lenP=my_strlen(product);
	if(product[0]=='0')
		for(i=0;i<lenP;i++)
			product[i]=product[i+1];
	if(flaga*flagb==-1)
		printf("-");
	printf("%s\n",product);
	flaga=flagb=1;
}
int main()
{
	int T,lenA,lenB,flagA,flagB,i;
	flagA=flagB=1;
	char A[696969],B[696969],input;
	scanf("%d",&T);
	while(T--)
	{       
		flagA=flagB=1;
		scanf("%s%s",A,B);
		lenA=my_strlen(A);
		lenB=my_strlen(B);
		if(A[0]=='-')
		{
			flagA=-1;
			for(i=0;i<lenA;i++)
				A[i]=A[i+1];
		}
		if(B[0]=='-')
		{
			flagB=-1;
			for(i=0;i<lenB;i++)
				B[i]=B[i+1];
		}
		m(A,B,flagA,flagB);
	}       
	return 0;
} 
