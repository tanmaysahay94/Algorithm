#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

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
	string str;
	cin >> str;
	int n, l, r;
	VI pre(str.length(), 0);
	for (int i = 1; i < (int) pre.size(); i++)
		pre[i] = pre[i-1] + (str[i] == str[i-1]);
	cin >> n;
	while (n--)
	{
		cin >> l >> r;
		cout << pre[r-1] - pre[l-1] << endl;
	}
	return 0;
}
