#include<stdio.h>
#include<string.h>
#include<math.h>
int isPalindrome(int n)
{
	int i,lenCheck;
	char check[20];
	sprintf(check,"%d",n);
	lenCheck=strlen(check);
	for(i=0;i<lenCheck/2;i++)
		if(check[i]!=check[lenCheck-i-1])
			return 0;
	return 1;
}
int isPrime(int n)
{
	int i,c;
	int itLim=sqrt(n);
	if(n==1)
		return 0;
	else if(n==2||n==3)
		return 1;
	else
	{
		c=0;
		if(n%6==1||n%6==5)
		{
			for(i=3;i<=itLim;i+=2)
				if(!(n%i))
				{
					c=1;
					break;
				}
		}
		else
			return 0;
	}
	return !c;
}
int main()
{
	int input;
	scanf("%d",&input);
	if(input!=2&&!(input%2))
		input++;
	while(1)
	{
		if(isPalindrome(input))
			if(isPrime(input))
				break;
		input+=2;
	}
	printf("%d",input);
	return 0;
} 
