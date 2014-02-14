/* FIFA 2014 World Cup Draw Simulator created by Tanmay Sahay and debugged by Nisarg Jhaveri on Dec 6, 2013 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Initializing the structures
typedef struct country
{
	char name[20];
	char continent[10];
	int placed;
}country;
typedef struct group
{
	country c[4];
	int asiaCount,europeCount,africaCount,southAmericaCount,northAmericaCount,curr;
}group;
typedef struct pot
{
	country CNT[9];
	int countryCount;
}pot;
//Initialization of structures complete
int main()
{
	int placedEuropean,i,j,sudoRandom1,sudoRandom2;
	time_t t;			//random number generator using time structure
	srand((unsigned)time(&t));
	//Initializing the 4 Pots
	pot p[4]={{{{"Brazil","SA",0},{"Argentina","SA",0},{"Colombia","SA",0},{"Uruguay","SA",0},{"Belgium","EU",0},{"Germany","EU",0},{"Spain","EU",0},{"Switzerland","EU",0}},8},{{{"Algeria","CAF",0},{"Cameroon","CAF",0},{"Côte d’Ivoire","CAF",0},{"Ghana","CAF",0},{"Nigeria","CAF",0},{"Chile","SA",0},{"Ecuador","SA",0}},7},{{{"Australia","ASIA",0},{"Iran","ASIA",0},{"Japan","ASIA",0},{"Korea Republic","ASIA",0},{"Costa Rica","NA",0},{"Honduras","NA",0},{"Mexico","NA",0},{"USA","NA",0}},8},{{{"Bosnia-Herzegovina","EU",0},{"Croatia","EU",0},{"England","EU",0},{"France","EU",0},{"Greece","EU",0},{"Italy","EU",0},{"Netherlands","EU",0},{"Portugal","EU",0},{"Russia","EU",0}},9}};
	//Pot Initialization complete
	group g[8];			//groups initialized
	//Sending 1 European team from Pot 4 to Pot 2
	placedEuropean=sudoRandom1=rand()%9;		//team randomly selected
	p[1].CNT[7]=p[3].CNT[sudoRandom1];	//team placed in pot 2
	p[1].countryCount++;
	p[3].countryCount--;
	//1 European team sent from Pot 4 to Pot 2
	for(i=0;i<8;i++)
	{
		p[0].CNT[i].placed=0;
		p[1].CNT[i].placed=0;
		p[2].CNT[i].placed=0;
		p[3].CNT[i].placed=0;
		g[i].curr=g[i].asiaCount=g[i].africaCount=g[i].southAmericaCount=g[i].northAmericaCount=g[i].europeCount=0;
	}
	g[0].c[0]=p[0].CNT[0];
	g[0].southAmericaCount=g[0].curr=1;
	p[0].countryCount--;
	p[0].CNT[0].placed=1;
	for(i=1;i<8;i++)
		g[i].curr=0;
	//Group A has 1 team: Brazil
	while(p[0].countryCount)
	{
		sudoRandom1=rand()%7+1;	//Picking the country from the pot
		if(!p[0].CNT[sudoRandom1].placed)
		{
			sudoRandom2=rand()%8;
			if(!g[sudoRandom2].curr)	//picking the group
			{
				p[0].CNT[sudoRandom1].placed=1;
				p[0].countryCount--;
				g[sudoRandom2].curr=1;
				strcpy(g[sudoRandom2].c[0].name,p[0].CNT[sudoRandom1].name);
				strcpy(g[sudoRandom2].c[0].continent,p[0].CNT[sudoRandom1].continent);
				if(!strcmp(g[sudoRandom2].c[0].continent,"SA"))
					++g[sudoRandom2].southAmericaCount;
				else if(!strcmp(g[sudoRandom2].c[0].continent,"EU"))
					++g[sudoRandom2].europeCount;
			}
		}
	}
	//All the groups have 1 seed
	sudoRandom1=rand()%4;
	for(i=0;i<7;i++)
	{
		if(!strcmp(p[0].CNT[sudoRandom1].name,g[i].c[0].name))
		{
			p[1].CNT[7].placed=p[3].CNT[placedEuropean].placed=1;
			p[1].countryCount--;
			g[i].curr=2;
			strcpy(g[i].c[1].name,p[1].CNT[7].name);
			strcpy(g[i].c[1].continent,p[1].CNT[7].continent);
			++g[i].europeCount;
			break;
		}
	}
	//European team now placed with a South American Nation
	while(p[1].countryCount)//allotting teams in Pot 2 to groups
	{
		for(i=0;i<7;i=((i+1)%7))
		{
			if(!g[i].africaCount)		//if no African country present, place an African country in the group
			{
				sudoRandom1=rand()%5;
				if(!p[1].CNT[sudoRandom1].placed)
				{
					p[1].CNT[sudoRandom1].placed=1;
					p[1].countryCount--;
					g[i].curr++;
					strcpy(g[i].c[g[i].curr-1].name,p[1].CNT[sudoRandom1].name);
					strcpy(g[i].c[g[i].curr-1].continent,p[1].CNT[sudoRandom1].continent);
					g[i].africaCount++;
					if(!p[1].countryCount)
						break;
					continue;
				}
			}
			if(!g[i].southAmericaCount)	//if no South American country present, place a South American country in the group
			{
				sudoRandom1=rand()%2+5;
				if(!p[1].CNT[sudoRandom1].placed)
				{
					p[1].CNT[sudoRandom1].placed=1;
					p[1].countryCount--;
					g[i].curr++;
					strcpy(g[i].c[g[i].curr-1].name,p[1].CNT[sudoRandom1].name);
					strcpy(g[i].c[g[i].curr-1].continent,p[1].CNT[sudoRandom1].continent);
					g[i].southAmericaCount++;
					if(!p[1].countryCount)
						break;
				}
			}
		}
	}
	//Pots 1 and 2 now empty
	//Emptying Pot 3: Asian and North American teams
	for(i=0;i<8;i++)//Group has been selected
	{
a:		sudoRandom1=rand()%8;
		if(!p[2].CNT[sudoRandom1].placed)
		{
			if(!strcmp("ASIA",p[2].CNT[sudoRandom1].continent))
				g[i].asiaCount++;
			else
				g[i].northAmericaCount++;
			p[2].CNT[sudoRandom1].placed=1;
			p[2].countryCount--;
			g[i].curr++;
			strcpy(g[i].c[g[i].curr-1].name,p[2].CNT[sudoRandom1].name);
			strcpy(g[i].c[g[i].curr-1].continent,p[2].CNT[sudoRandom1].continent);
		}
		else
			goto a;
	}
/*	//Emptying Pot 4. Checking condition: Groups are NOT FULL
b:	sudoRandom1=rand()%8;
	if(g[sudoRandom1].curr<4)	//place country in a group only if group is not full
	{
		while(p[3].countryCount)//place while countries remain in the pot
		{
			sudoRandom2=rand()%9;
			if(!p[3].CNT[sudoRandom2].placed)	//place a country only if it hasn't been placed yet
			{
				p[3].CNT[sudoRandom2].placed=1;
				p[3].countryCount--;
				strcpy(g[sudoRandom1].c[g[sudoRandom1].curr].name,p[3].CNT[sudoRandom2].name);
				strcpy(g[sudoRandom1].c[g[sudoRandom1].curr].continent,p[3].CNT[sudoRandom2].continent);
				g[sudoRandom1].curr++;
			}
		}
	}
	else
		goto b;
*/	//---------------------------------------------------------------------This segment of code works too till here-------------------------------------------//
	for(i=0;i<8;i++)
	{
		printf("#%d eu:%d sa:%d caf:%d na:%d as:%d curr:%d\n",i+1,g[i].europeCount,g[i].southAmericaCount,g[i].africaCount,g[i].northAmericaCount,g[i].asiaCount,g[i].curr);
		for(j=0;j<4;j++)
			printf("%s ",g[i].c[j].name);
		printf("\n");
	}
	return 0;
}
