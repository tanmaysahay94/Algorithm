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

LL powMod(LL a, LL b, LL mod)
{
	a %= mod;
	LL ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	string s;
	LL a, b;
	cin >> s >> a >> b;
	LL len = s.length();
	VLL rema(len), remb(len);
	rema[0] = (s[0] - '0') % a;
	for (LL i = 1; i < len; i++)
		rema[i] = ((10*rema[i-1])%a + (s[i]-'0'))%a;
	remb[len-1] = (s[len-1] - '0') % b;
	LL j;
	for (LL i = len - 2, j = 1; i >= 0; i--, j++)
		remb[i] = (((s[i]-'0')*powMod(10, j, b))%b + remb[i+1])%b;
	bool possible = false;
	LL i;
	for (i = 0; i < len - 1; i++)
		if (rema[i] == 0 and remb[i+1] == 0 and s[i+1] != '0')
		{
			possible = true;
			break;
		}
	if (!possible)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (LL j = 0; j < len; j++)
			if (j == i)
				printf("%c\n", s[j]);
			else
				printf("%c", s[j]);
	}
	return 0;
}
