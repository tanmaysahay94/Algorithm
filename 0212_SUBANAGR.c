#include<stdio.h>
int main()
{
	int n,i,w[26],f[26],j,nss=1;
	char s[150];
	for(i=0;i<26;i++)
		f[i]=0;
	scanf("%d",&n);
	n--;
	scanf("%s",s);
	for(i=0;s[i];i++)
		f[s[i]-'a']++;
	while(n--)
	{
		for(i=0;i<26;i++)
			w[i]=0;
		scanf("%s",s);
		for(i=0;s[i];i++)
			w[s[i]-'a']++;
		for(i=0;i<26;i++)
			f[i]=f[i]<w[i]?f[i]:w[i];
	}
	for(i=0;i<26;i++)
	{
		nss*=!f[i];
		for(j=0;j<f[i];j++)
			printf("%c",i+'a');
	}
	if(nss)
		printf("no such string\n");
	else
		printf("\n");
	return 0;
}
