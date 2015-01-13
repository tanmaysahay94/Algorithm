#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

inline LL read()
{
	LL n = 0;
	char c;
	while ((c = getchar_unlocked()) < '0');
	n += c - '0';
	while ((c = getchar_unlocked()) >= '0')
		n = (n << 3) + (n << 1) + (c - '0');
	return n;
}

inline void write(LL a)
{
	char snum[20];
	int i = 0;
	do
	{
		snum[i++] = a%10 + 48;
		a /= 10;
	} while(a);
	i--;
	while(i >= 0)
		putchar_unlocked(snum[i--]);
	putchar_unlocked('\n');
}

VLL a;

int main()
{
	LL t;
	t = read();
	while (t--)
	{
		LL n, q;
		n = read();
		q = read();
		a = VLL (n);
		for (int i = 0; i < n; i++)
			a[i] = read();
		VLL left(n + 1, 0), right(n + 1, 0);
		for (int i = 1; i <= n; i++)
			left[i] = __gcd(left[i - 1], a[i - 1]);
		for (int i = n - 1; i >= 0; i--)
			right[i] = __gcd(right[i + 1], a[i]);
		while (q--)
		{
			LL l, r;
			l = read(); r = read();
			write(__gcd(left[l - 1], right[r]));
		}
	}
}
