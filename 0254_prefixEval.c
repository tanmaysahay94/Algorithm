#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct prefix
{
	long long int data;
	struct prefix *link;
}prefix;
int main()
{
	long long int i,t,top,count,valid,charCount,opCount;
	char e[10000];
	scanf("%lld",&t);
	while(t--)
	{
		charCount=opCount=count=0;
		valid=1;
		prefix *temp,*out=NULL;
		scanf("%s",e);
		for(i=strlen(e)-1;i>=0;i--)
		{
			if(e[i]>='0'&&e[i]<='9')
			{
				charCount++;
				count++;
				temp=(prefix*)malloc(sizeof(prefix));
				temp->data=(long long int)(e[i]-'0');
				if(out==NULL)
					temp->link=NULL;
				else
					temp->link=out;
				out=temp;
			}
			else
			{
				opCount++;
				if(count>=2)
				{
					top=out->data;
					out=out->link;
					count--;
					if(e[i]=='+')
						out->data+=top;
					else if(e[i]=='-')
						out->data=top-out->data;
					else if(e[i]=='/')
					{
						if(out->data)
							out->data=top/out->data;
						else
						{
							printf("invalid");
							break;
						}
					}
					else if(e[i]=='*')
						out->data*=top;
					else if(e[i]=='^')
						out->data=(long long int)pow(top,out->data);
				}
				else
				{
					valid=0;
					break;
				}
			}
		}
		if(valid)
			valid=(out->link==NULL&&charCount==opCount+1);
		if(valid)
			printf("%lld\n",out->data);
		else
			printf("invalid\n");
		while(out!=NULL)
			out=out->link;
	}
	return 0;
}
