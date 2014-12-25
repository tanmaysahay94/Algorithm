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
	int open(0), close(0), balance(0);
	VI ans;
	bool possible(true);
	for (int i = 0; str[i] and possible; i++)
	{
		if (str[i] == '(')
			balance++, open++;
		else if (str[i] == ')')
			balance--, close += (bool) open;
		else
			balance--, ans.pb(1), open = close = 0;
		if (balance < 0)
			possible = false;
	}
	if (not possible or close < open)
		cout << "-1\n";
	else
	{
		ans[ans.size() - 1] += balance;
		each(it, ans)
			cout << *it << endl;
	}
	return 0;
}
