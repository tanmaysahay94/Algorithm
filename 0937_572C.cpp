#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;
const LL mod = 3e5 + 7;

bool yes(LL a, LL b, LL c)
{
	return ((a + b > c) and (b + c > a) and (c + a > b));
}

LL solve(LL a, LL b, LL c, LL l)
{
	queue<pair<LL, pair<LL, pair<LL, LL> > > > Q;
	Q.push(make_pair(a, make_pair(b, make_pair(c, l))));
	set<LL> S;
	LL ans = 0;
	while (not Q.empty())
	{
		pair<LL, pair<LL, pair<LL, LL> > > rem = Q.front();
		Q.pop();
		LL A = rem.first, B = rem.second.first, C = rem.second.second.first, L = rem.second.second.second;
		LL foo = mod * mod * A + mod * B + C;
		if (S.count(foo) == 0)
			S.insert(foo);
		else
			continue;
		ans += yes(A, B, C);
		if (L)
		{
			if (A + 1 < B + C + L - 1 and S.count(mod * mod * (A + 1) + mod * B + c) == 0)
				Q.push(make_pair(A + 1, make_pair(B, make_pair(C, L - 1))));
			if (B + 1 < C + A + L - 1 and S.count(mod * mod * A + mod * (B + 1) + c) == 0)
				Q.push(make_pair(A, make_pair(B + 1, make_pair(C, L - 1))));
			if (C + 1 < A + B + L - 1 and S.count(mod * mod * A + mod * B + C + 1) == 0)
				Q.push(make_pair(A, make_pair(B, make_pair(C + 1, L - 1))));
		}
	}
	return ans;
}

int main()
{
	optimizeIO();
	LL a, b, c, l;
	cin >> a >> b >> c >> l;
	cout << solve(a, b, c, l);
	return 0;
}
