#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin >> n;
	vector<LL> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	vector<pair<LL, LL> > in(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> in[i].first;
		in[i].second = i;
	}
	sort(in.rbegin(), in.rend());
	vector<LL> out(5);
	LL total = 0;
	for (auto P: p)
	{
		total += P;
		for (int i = 0; i < 5; i++)
		{
			LL cost = in[i].first;
			LL num = total / cost;
			out[in[i].second] += num;
			total -= num * cost;
		}
	}
	for (auto o: out)
		cout << o << ' '; cout << endl; cout << total;
	return 0;
}
