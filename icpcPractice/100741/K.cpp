#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if(n%2 == 0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int cnt1[1010] = {0};	//ith player has WON cnt1 games.
	int cnt2[1010] = {0};	//ith player has LOST cnt2 games
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
			if(cnt1[i] < n/2 && cnt2[j] < n/2)
			{
				cout<<"1 ";
				cnt1[i]++;
				cnt2[j]++;
			}
			else
			{
				cout<<"0 ";
				cnt2[i]++;
				cnt1[j]++;
			}
		cout<<endl;
	}
	return 0;
}
