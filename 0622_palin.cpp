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
	int n, p;
	cin >> n >> p;
	string str;
	cin >> str;
	int i = n - 1;
	str[i]++;
	while (i >= 0 and i < n)
	{
		if (str[i] > 'a' + p - 1)
		{
			str[i] = 'a';
			i--;
			str[i]++;
		}
		else if (i > 0 and str[i] == str[i - 1])
			str[i]++;
		else if (i > 1 and str[i] == str[i - 2])
			str[i]++;
		else
			i++;
	}
	if (i < 0)
		cout << "NO\n";
	else
		cout << str << endl;
	return 0;
}
