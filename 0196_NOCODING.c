#include<stdio.h>
int main()
{
	int t,a,i;
	char d,word[1000];
	scanf("%d",&t);
	scanf("%c",&d);
	while(t--)
	{
		scanf("%s",word);
		for(a=2,i=1;word[i];i++)
		{
			if(word[i]>=word[i-1])
				a+=1+word[i]-word[i-1];
			else
				a+=27+word[i]-word[i-1];
		}
		if(a>11*i)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
