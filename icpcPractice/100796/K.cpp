#include <bits/stdc++.h>

using namespace std;

vector<long long> fact;
unordered_set<long long> perms;

int main()
{
	long long fc = 1;
	for(int i = 2; i <= 20; i++)
	{
		fc *= i;
		fact.push_back(fc);
	}
	perms.insert(1);
	for(int i = 0; i < (int)fact.size(); i++)
	{
		unordered_set<long long> temp;
		for(auto p:perms)
		{
			long long pwr = fact[i];
			while(p <= 1e18 / pwr)
			{
				temp.insert(p*pwr);
				pwr *= fact[i];
			}
		}
		for(auto t:temp)
			perms.insert(t);
	}
	int n;
	long long tc;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> tc;
		if(perms.count(tc) == 0)
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
	}
	return 0;
}
