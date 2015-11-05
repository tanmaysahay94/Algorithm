#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL dist(char a, char b)
{
	LL val = abs(a - b);
	return min(val, 26 - val);
}

int main()
{
	LL n, pos;
	string s;
	cin >> n >> pos >> s;
	s = " " + s;
	LL start, end, ans = 0;
	if (pos <= n/2)
		start = 1, end = n/2;
	else
		end = n, start = (n/2) + 1;
	while (dist(s[start], s[n - start + 1]) == 0 and start < pos)
		start++;
	while (dist(s[end], s[n - end + 1]) == 0 and end > pos)
		end--;
	ans += 2 * min(abs(pos - start), abs(end - pos)) + max(abs(pos - start), abs(end - pos));
	for (LL i = start; i <= end; i++)
		ans += dist(s[i], s[n - i + 1]);
	cout << ans << endl;
	return 0;
}
