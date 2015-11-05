#include<stdio.h>
inline int read()
{
	char c;
	int n = 0;
	while((c=getchar_unlocked())<'0');
	n+=(c-'0');
	while((c=getchar_unlocked())>='0')
		n=n*10+(c-'0');
	return n;
}
int main()
{
	int t,leaves,levels,valid,prev;
	t=read();
	while(t--)
	{
		prev=1;					//prev: total number of stems possible at a given level from previous level
		valid=1;
		levels=read();
		while(levels--)
		{
			leaves=read();			//leaves: number of leaves at a given level
			if(leaves>prev)
			{
				valid=0;
				break;
			}
			prev=2*(prev-leaves);		//number of stems going to the next level
		}
		if(!valid||prev)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
