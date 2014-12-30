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
	LL n;
	cin >> n;
	VLL v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<string> str(n);
	vector<VI> mat(n, VI (n));
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = str[i][j] - '0';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				mat[j][k] |= mat[j][i] & mat[i][k];
	for (int i = 0; i < n; i++)
	{
		int idx = 0;
		for (int j = 0; j < n; j++)
			if (v[j] == i)
				idx = j;
		for (int j = 0; j <= idx; j++)
			if (v[j] > i and mat[idx][j])
				swap(v[j], v[idx]);
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}
