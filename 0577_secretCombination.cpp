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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n;
	string str;
	cin >> n >> str;
	vector<string> v;
	for (int i = 0; i < 10; i++)
	{
		string ans = "";
		for (int j = 0; j < n; j++)
			ans += '0' + (str[j] - '0' + i)%10;
		v.pb(ans);
		for (int j = 0; j < n; j++)
		{
			ans = ans.substr(1) + ans[0];
			v.pb(ans);
		}
		sortv(v);
	}
	cout << v[0] << endl;
	return 0;
}
