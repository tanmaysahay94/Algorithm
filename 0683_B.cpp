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

LL cdiv(LL a, LL b)
{
	return (a - 1)/b + 1;
}

bool check(vector<VLL>& col, LL n, LL k)
{
	for (LL i = 0; i < k; i++)
		for (LL j = 1; j < n; j++)
			if (abs(col[i][j] - col[i][j - 1]) > 1)
				return false;
	return true;
}

int main()
{
	LL n, k, high = -11111, low = 11111;
	cin >> n >> k;
	VLL npeb(n);
	for (LL i = 0; i < n; i++)
	{
		cin >> npeb[i];
		if (npeb[i] > high)
			high = npeb[i];
		if (npeb[i] < low)
			low = npeb[i];
	}
	vector<VLL> col(k, VLL (n, 0LL));
	for (LL i = 0; i < n; i++)
		for (LL cnt = 0; cnt < npeb[i]; cnt++)
			col[cnt % k][i]++;
	if (high - low > k or not check(col, n, k))
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (LL i = 0; i < n; i++, cout << endl)
			for (LL j = 0; j < k; j++)
				for (LL cnt = 0; cnt < col[j][i]; cnt++)
					cout << j + 1 << ' ';
	}
	return 0;
}
