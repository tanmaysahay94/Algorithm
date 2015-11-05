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

LL level(LL val)
{
	LL ret = 0;
	while (val)
	{
		ret++;
		val >>= 1;
	}
	return ret;
}

int main()
{
	LL q, x, y, root = 0;
	char s[4];
	SLL(q);
	while (q--)
	{
		scanf("%s", s);
		if (s[1] == 'i')
			root ^= 1LL;
		else
		{
			SLL(x); SLL(y);
			LL xl = level(x);
			LL yl = level(y);
			if (s[1] == 'b')
			{
				LL black = 0;
				while (x != y)
				{
					if (x > y)
					{
						black += (root ^ (xl%2));
						x >>= 1;
						xl--;
					}
					else
					{
						black += (root ^ (yl%2));
						y >>= 1;
						yl--;
					}
				}
				black += (root ^ (xl % 2));
				printf("%lld\n", black);
			}
			else if (s[1] == 'r')
			{
				LL red = 0;
				while (x != y)
				{
					if (x > y)
					{
						red += (root == (xl%2));
						x >>= 1;
						xl--;
					}
					else
					{
						red += (root == (yl%2));
						y >>= 1;
						yl--;
					}
				}
				red += (root == (xl%2));
				printf("%lld\n", red);
			}
		}
	}
	return 0;
}
