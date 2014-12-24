#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n, m;
	cin >> n >> m;
	map<string, string> dict;
	string fir, sec;
	while (m--)
	{
		cin >> fir >> sec;
		if (sec.length() < fir.length())
			dict[fir] = sec;
		else
			dict[fir] = fir;
	}
	while (n--)
	{
		cin >> fir;
		cout << dict[fir] << " ";
	}
	cout << endl;
	return 0;
}
