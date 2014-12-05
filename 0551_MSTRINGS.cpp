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

int isPalin(string& str)
{
	LL len = str.length();
	for (LL i = 0; i < len/2; i++)
		if (str[i] != str[len - i - 1])
			return 0;
	return 1;
}

int main()
{
	LL t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		if (isPalin(str)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
