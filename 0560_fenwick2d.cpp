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

class fenwick2d {
	int n;
	vector<VLL> ft;
	public:
	fenwick2d(int N): n(N) {
		ft = vector<VLL> (n + 1, VLL (n + 1, 0LL));
	}
	void set(int x, int y, LL val) {
		val -= get(x, y, x, y);
		while (x <= n) {
			int tmp = y;
			while (tmp <= n) {
				ft[x][tmp] += val;
				tmp += tmp&-tmp;
			}
			x += x&-x;
		}
	}
	LL get(int x, int y) {
		LL sum = 0;
		while (x) {
			int tmp = y;
			while (tmp) {
				sum += ft[x][tmp];
				tmp -= tmp&-tmp;
			}
			x -= x&-x;
		}
		return sum;
	}
	LL get(int x1, int y1, int x2, int y2) {
		return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
	}
};

int main()
{
	int t, n, x, y, p, q;
	LL val;
	char str[5];
	si(t);
	while (t--)
	{
		si(n);
		fenwick2d ft(n);
		scanf("%s", str);
		while (str[0] != 'E') 
		{
			if (str[1] == 'E')
			{
				si(x); si(y); sll(val);
				ft.set(x + 1, y + 1, val);
			}
			else
			{
				si(x); si(y); si(p); si(q);
				printf("%lld\n", ft.get(x + 1, y + 1, p + 1, q + 1));
			}
			scanf("%s", str);
		}
	}
	return 0;
}
