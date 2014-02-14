#include<stdio.h>
#include<string.h>
int check(char p[],char q[],int j,int limit)
{
	int k;
	for(k=0;k<limit;k++)
	{
		if(j==limit)
			j=0;
		if(p[k]==q[j])
			j++;
		else
			return 0;
	}
	return 1;
}
int main()
{
	int T,lena,lenb,i,veritum=0;
	char a[10000],b[10000];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",a,b);
		lena=strlen(a);
		lenb=strlen(b);
		if(lena!=lenb)
			printf("NO\n");
		else
		{
			for(i=0;i<lena;i++)
			{
				if(*a==*(b+i))
					if(check(a,b,i,lena))
						veritum=1;
				if(veritum)
					break;
			}
		if(veritum)
			printf("YES\n");
		else
			printf("NO\n");
		veritum=0;
		}
	}
	return 0;
}
