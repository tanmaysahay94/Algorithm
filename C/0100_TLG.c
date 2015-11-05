#include<stdio.h>
#include<math.h>
int main()
{
	int nRounds,rd,winner,curMax,tScore1,tScore2,max=-1;
	scanf("%d",&nRounds);
	int game[nRounds][2];
	tScore1=tScore2=0;
	for(rd=0;rd<nRounds;rd++)
	{
		scanf("%d%d",&game[rd][0],&game[rd][1]);
		tScore1+=game[rd][0];
		tScore2+=game[rd][1];
		curMax=fabs(tScore1-tScore2);
		if(curMax>max)
		{
			max=curMax;
			if(game[rd][0]>game[rd][1])
				winner=1;
			else
				winner=2;
		}
	}
	printf("%d %d\n",winner,max);
	return 0;
} 
