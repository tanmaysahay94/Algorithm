#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n, i, max = 0;
	string in;
	map <string, int> contestant;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> in;
		if (contestant.find(in) == contestant.end())
			contestant[in] = 1;
		else
			contestant[in]++;
		if (contestant[in] > max)
		{
			max = contestant[in];
			cout << max << " " << in << endl;
		}
	}
	return 0;
}
