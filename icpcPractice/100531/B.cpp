#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("buffcraft.in");
	ofstream fout("buffcraft.out");
	int k, n, m;
	double b;
	fin >> b >> k >> n >> m;
	vector<pair<double, int> > add(n), mul(m);
	for (int i = 0; i < n; i++)
	{
		fin >> add[i].first;
		add[i].second = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		fin >> mul[i].first;
		mul[i].second = i + 1;
	}
	sort(add.rbegin(), add.rend());
	sort(mul.rbegin(), mul.rend());
	vector<double> preadd(n + 1), premul(m + 1);
	preadd[0] = 0;
	for (int i = 1; i <= n; i++)
		preadd[i] = preadd[i - 1] + add[i - 1].first;
	premul[0] = 0;
	for (int i = 1; i <= m; i++)
		premul[i] = premul[i - 1] + mul[i - 1].first;
	int addp = min(k, n);
	int diff = k - addp;
	int mulp = min(diff, m);
	int addans = addp, mulans = mulp;
	double ans = INT_MIN;
	while (addp > 0 and mulp <= m)
	{
		double tmp = (b + preadd[addp]) * (100.0 + premul[mulp]) / 100.0;
		if (tmp > ans)
		{
			ans = tmp;
			addans = addp;
			mulans = mulp;
		}
		addp--;
		mulp++;
	}
	mulp = min(k, m);
	diff = k - mulp;
	addp = min(diff, n);
	while (mulp > 0 and addp <= n)
	{
		double tmp = (b + preadd[addp]) * (100.0 + premul[mulp]) / 100.0;
		if (tmp > ans)
		{
			ans = tmp;
			addans = addp;
			mulans = mulp;
		}
		addp++;
		mulp--;
	}
	fout << addans << ' ' << mulans << endl;
	for (int i = 0; i < addans; i++)
		fout << add[i].second << ' '; fout << endl;
	for (int i = 0; i < mulans; i++)
		fout << mul[i].second << ' '; fout << endl;
	return 0;
}
