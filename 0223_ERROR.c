#include<stdio.h>
#include<string.h>
int main()
{
	int t,good,lenS,startLim,start,checked;
	char s[200000];
	scanf("%d",&t);
	while(t--)
	{
		good=0;
		scanf("%s",s);
		lenS=strlen(s);
		startLim=lenS-3;
		for(start=0;start<=startLim;start++)
		{
			checked=0;
			if(s[start]=='0')
			{
				checked=1;
				if(s[start+1]=='1')
					if(s[start+2]=='0')
					{
						good=1;
						break;
					}
			}
			if(!checked)
				if(s[start]=='1')
					if(s[start+1]=='0')
						if(s[start+2]=='1')
						{
							good=1;
							break;
						}
		}
		if(good)
			printf("Good\n");
		else
			printf("Bad\n");
	}
	return 0;
}
