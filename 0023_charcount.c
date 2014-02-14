#include<stdio.h>
int main()
{
	int d[10],w,o,ch;
	w=o=ch=0;
	int i;
	char c;
	for(i=0;i<10;i++)
		d[i]=0;
	while((c=getchar())!=EOF)
	{
		if(c>='0'&&c<='9')
			d[c-48]++;
		else if(c==' '||c=='\n'||c=='\t')
			w++;
		else if(c>='a'&&c<='z')
			ch++;
		else if(c>='A'&&c<='Z')
			ch++;
		else 
			o++;
	}
	for(i=0;i<=9;i++)
		printf("%d\n",d[i]);
	printf("%d\n",w);
	printf("%d\n",ch);
	printf("%d\n",o);
	return 0;
}
