#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int size(int k)
{
	if(k==1000000)
		return 7;
	else if(k>=100000)
		return 6;
	else if(k>=10000)
		return 5;
	else if(k>=1000)
		return 4;
	else if(k>=100)
		return 3;
	else if(k>=10)
		return 2;
	else
		return 1;
}

int main()
{
	int T,n,k,i,j,l,sk,si,count,found;
	cin >> T;
	while(T--)
	{
		count=0;
		cin >> n;
		cin >> k;
		sk=size(k);
		char srch[k+1];
		char nstring[1000000];
		int ncount=0;
		itoa(k,srch,10);
		for(i=1;i<=n;i++)
		{
			si=size(i);
			char tmp[si];
			itoa(i,tmp,10);
			for(j=0;j<si;j++)
			{
				nstring[ncount++]=tmp[j];
			}
		}
		nstring[ncount]='\0';
		for(j=0;j<ncount-sk;j++)
		{
			found=1;
			if(nstring[j]==srch[0])
			{
				for(i=1;i<k;i++)
					if(nstring[j+i]!=srch[i])
					{
						found=0;
						break;
					}
			}
			count+=found;
			if(!found)
				found=1;
		}
		cout << count;
	}
	return 0;
}
