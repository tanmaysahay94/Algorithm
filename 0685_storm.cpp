#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	int n, x, y, p, q;
	cin >> n >> x >> y;
	set<pair<int, int> > lines;
	while (n--)
	{
		cin >> p >> q;
		p -= x;
		q -= y;
		int g = __gcd(p, q);
		p /= g;
		q /= g;
		lines.insert(make_pair(p, q));
	}
	cout << lines.size() << endl;
	return 0;
}
