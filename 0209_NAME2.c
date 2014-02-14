#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j,lh,lw,marriage;
	char h[50000],w[50000];
	scanf("%d",&t);
	while(t--)
	{
		marriage=0;
		scanf("%s%s",h,w);
		lh=strlen(h);
		lw=strlen(w);
		if(lh>=lw)
		{
			i=j=0;
			while(i<lw&&j<lh)
			{
				if(w[i]==h[j])
					i++;
				j++;
			}
			if(i==lw)
				marriage=1;
		}
		else
		{
			i=j=0;
			while(i<lh&&j<lw)
			{
				if(h[i]==w[j])
					i++;
				j++;
			}
			if(i==lh)
				marriage=1;
		}
		if(marriage)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
