#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<long long> a;
	vector<long long> b;
	int n, m;
	long long val;
	unordered_map<long long, int> ma, mb;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &val);
		vector<long long> temp;
		for(auto j:a)
		{
			temp.push_back(j+val);
		}
		for(auto t:temp)
			a.push_back(t);
		a.push_back(val);
	}
	for(int i=0; i<m; i++)
	{
		scanf("%lld", &val);
		vector<long long> temp;
		for(auto j:b)
		{
			temp.push_back(j+val);
		}
		for(auto t:temp)
			b.push_back(t);
		b.push_back(val);
	}
	for(auto i:a)
	{
//		cout << i << " ";
		ma[i] += 1;
	}
//	cout << endl;
	for(auto j:b)
	{
//		cout << j << " ";
		mb[j] += 1;
	}
//	cout << endl;
	int count = 0;
	for(auto m:ma )
	{
		count += m.second * mb[m.first];
	}
	cout << count << endl;
	return 0;
}
