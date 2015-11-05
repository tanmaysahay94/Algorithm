#include<stdio.h>
int main()
{
	int N;
	char c;
	scanf("%d",&N);
	while(N>0)
	{
		scanf("%c",&c);
		if(c==10||c==32)
			scanf("%c",&c);
		if(c>='A'&&c<='Z')
			printf("UPPER CASE CHARACTER\n");
		else if(c>='a'&&c<='z')
			printf("LOWER CASE CHARACTER\n");
		else if(c>='0'&&c<='9')
			printf("NUMERAL\n");
		else
			printf("NON-ALPHANUMERAL\n");
		N--;
	}
	return 0;
}
