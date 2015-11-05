#include <stdio.h>
 
int main()
{
	int t,i,holes;
	char text[200];
	scanf("%d",&t);
	while(t--)
	{
		holes=0;
		scanf("%s",text);
		for(i=0;text[i];i++)
		{
			switch(text[i])
			{
				case 'B': holes+=2; break;
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R': holes++; break;
				case 'C':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z': break;
			}
		}
		printf("%d\n",holes);
	}
	return 0;
}
