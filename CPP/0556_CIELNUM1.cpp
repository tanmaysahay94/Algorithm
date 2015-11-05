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

char str[100];
int i, total = 0;

void generate(int n, int n3, int n5, int n8)
{
	if (total == 50000)
		return;
	if (n == i)
	{
		if (n8 >= n5 and n5 >= n3)
		{
			printf("%s\n", str);
			total++;
		}
		return;
	}
	str[n] = '3';
	generate(n + 1, n3 + 1, n5, n8);
	str[n] = '5';
	generate(n + 1, n3, n5 + 1, n8);
	str[n] = '8';
	generate(n + 1, n3, n5, n8 + 1);
}

int main()
{
	for (i = 1; i < 100; i++)
		generate(0, 0, 0, 0);
	return 0;
}
