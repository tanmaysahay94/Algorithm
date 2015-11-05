#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n,m,k,p,a;
	int mas0[100005];
	int mas1[100005];
	bool can = true;
	int kolvo0=0, kolvo1=0;
	vector <vector <int> > g (100005);
	cin >> n >> k >> p;
	m = k - p;
	for (int i = 0; i<n; i++)
	{
		cin >> a;
		if (a%2)
			mas1[kolvo1++]=a;
		else
			mas0[kolvo0++]=a;
	}
	for (int i = 0; i<p && can; i++)//creating even partitions with even numbers and odd pairs
	{
		if (kolvo0>0)
			g[i].push_back(mas0[--kolvo0]);
		else if (kolvo0==0 && kolvo1>1)
		{
			g[i].push_back(mas1[--kolvo1]);
			g[i].push_back(mas1[--kolvo1]);
		}
		else
			can=false;
	}
	for (int i = 0; i<m && can; i++)//creating odd partitions
	{
		if (kolvo1>0)
			g[p+i].push_back(mas1[--kolvo1]);
		else
			can=false;
	}
	while(kolvo0>0)//filling up one of the even partitions with remaining even numbers
		g[0].push_back(mas0[--kolvo0]);
	if (kolvo1%2==1)
		can=false;
	else
		for (int i = 0; i<kolvo1; i+=2)
		{
			g[0].push_back(mas1[i]);
			g[0].push_back(mas1[i+1]);
		}
	if (!can)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		for (int i = 0; i<k; i++)
		{
			cout << g[i].size() << " ";
			for (int j = 0; j<(int)g[i].size(); j++)
				cout << g[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
