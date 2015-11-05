#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string S;
LL nb, ns, nc;
LL pb, ps, pc;
LL r;
LL hb, hs, hc;

bool possible(LL num_burgers)
{
	LL cost = 0;
	cost += max(0LL, num_burgers * hb - nb) * pb;
	cost += max(0LL, num_burgers * hs - ns) * ps;
	cost += max(0LL, num_burgers * hc - nc) * pc;
	return cost <= r;
}

int main()
{
	cin >> S >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	hb = hs = hc = 0;
	for (auto ing: S)
		if (ing == 'B') hb++;
		else if (ing == 'S') hs++;
		else hc++;
	LL low = 0, high = 1e14;
	while (high - low > 1)
	{
		LL mid = (high + low) / 2;
		if (possible(mid))
			low = mid;
		else
			high = mid;
	}
	cout << low;
	return 0;
}
