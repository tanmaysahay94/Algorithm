#include<stdio.h>
#include<string.h>
typedef struct charMap
{
	int fr;
	char mapTo,c;
}charMap;
int cmp(const void *a,const void *b)
{
	if((*(charMap*)a).fr==(*(charMap*)b).fr)
		return (*(charMap*)a).c-(*(charMap*)b).c;
	return (*(charMap*)a).fr-(*(charMap*)b).fr;
}
int cmpLetter(const void *a,const void *b)
{
	return (*(charMap*)a).c-(*(charMap*)b).c;
}
int main()
{
	int t,textSize,i;
	char cipher[26],text[696969],dump,input;
	scanf("%d",&t);
	while(t--)
	{
		textSize=0;
		charMap cm[26];
		for(i=0;i<26;i++)
		{
			cm[i].fr=0;
			cm[i].c=i+'a';
		}
		scanf("%s",cipher);
		scanf("%c",&dump);
		scanf("%c",&input);
		while(input!='\n')
		{
			text[textSize++]=input;
			if(input>='a'&&input<='z')
				cm[input-'a'].fr++;
			else if(input>='A'&&input<='Z')
				cm[input-'A'].fr++;
			scanf("%c",&input);
		}
		text[textSize]='\0';
		qsort(cm,26,sizeof(charMap),cmp);
		for(i=0;i<26;i++)
			cm[i].mapTo=cipher[i];
		qsort(cm,26,sizeof(charMap),cmpLetter);
		int p,q;
		for(i=0;text[i];i++)
			printf("%c",(p=(text[i]>='a'&&text[i]<='z'))*(cm[text[i]-'a'].mapTo)+(q=(text[i]>='A'&&text[i]<='Z'))*((cm[text[i]-'A'].mapTo)-32)+(!(p||q))*text[i]);
		printf("\n");
	}
	return 0;
}
