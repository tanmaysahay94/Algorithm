#include<stdio.h>
#include<string.h>
typedef struct fileType
{
	char formatName[15];
	char formatDesc[50];
	int lenFormatName;
}fileType;
int substringSearch(char big[],char small[],int lenBig,int lenSmall)
{
	int iterate,flag,r=lenBig-lenSmall;
	for(iterate=r;iterate<lenBig;iterate++)
	{
		flag=(big[iterate]==small[iterate-r]);
		if(!flag)
			break;
	}
	return flag;
}
int main()
{
	int given,nFile,d,i,j,l,found;
	char fName[70];
	scanf("%d%d%d",&given,&nFile,&d);
	fileType ft[given];
	for(i=0;i<given;i++)
	{
		scanf("%s%s",ft[i].formatName,ft[i].formatDesc);
		ft[i].lenFormatName=strlen(ft[i].formatName);
	}
	while(nFile--)
	{
		found=0;
		scanf("%s",fName);
		l=strlen(fName);
		for(i=0;i<given;i++)
			if(l>=ft[i].lenFormatName+1)
				if(fName[l-ft[i].lenFormatName-1]=='.')
					if(substringSearch(fName,ft[i].formatName,l,ft[i].lenFormatName))
					{
						found=1;
						printf("%s\n",ft[i].formatDesc);
						break;
					}
		if(!found)
			printf("unknown\n");
	}
	return 0;
}
