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
	if (str.length() == 1)
		if (str[0] == '0' or str[0] == '4' or str[0] == '8')
			cout << 4 << endl;
		else
			cout << 0 << endl;
	else
	{
		int num = str[str.length() - 1] - '0' + 10 * (str[str.length() - 2] - '0');
		if (num % 4 == 0)
			cout << 4 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
