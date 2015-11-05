#include <bits/stdc++.h>

using namespace std;

pair<long double, long long> transform(long double foo)
{
	if (foo == ((long double) 0))
		return make_pair(0, 0);
	long long exp = 0;
	while (foo < ((long double) 1))
	{
		foo *= 10;
		exp--;
	}
	return make_pair(foo, exp);
}

void multiply(pair<long double, long long>& a, pair<long double, long long> b)
{
	a.first *= b.first;
	a.second += b.second;
	if (a.first >= ((long double) 10))
	{
		a.first /= ((long double) 10);
		a.second++;
	}
}

void add(pair<long double, long long>& a, pair<long double, long long> b)
{
	if (a.second > b.second)
		swap(a, b);
	while (a.second < b.second)
	{
		a.first /= ((long double) 10);
		a.second++;
	}
	a.first += b.first;
	if (a.first >= ((long double) 10))
	{
		a.first /= ((long double) 10);
		a.second++;
	}
}

void divide(pair<long double, long long>& a, pair<long double, long long> b)
{
	if (b.first == ((long double) 0))
	{
		a.first = 1;
		a.second = 0;
		return;
	}
	a.first /= b.first;
	a.second -= b.second;
}

void show(pair<long double, long long>& a)
{
	if (a.second > 0)
	{
		while (a.second > 0)
		{
			a.first *= ((long double) 10);
			a.second--;
		}
	}
	else
	{
		while (a.second < 0)
		{
			a.first /= ((long double) 10);
			a.second++;
		}
	}
	printf("%.6Lf\n", a.first);
}

void hardcodeLOL(int n, int m)
{
	vector<long double> rowProd(n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			long double foo;
			scanf("%Lf", &foo);
			rowProd[i] *= foo;
		}
	if (n == 1)
	{
		printf("1.000000\n");
		return;
	}
	long double dividend = rowProd[0];
	long double foo = dividend;
	for (int i = 1; i < n; i++)
		foo += rowProd[i];
	foo = ((long double) 1) - foo;
	if (foo == ((long double) 1))
		printf("0.000000\n");
	else
		printf("%.6Lf\n", dividend / (((long double) 1) - foo));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n <= 4 and m <= 4)
		{
			hardcodeLOL(n, m);
			continue;
		}
		vector<pair<long double, long long> > rowProd(n);
		for (int i = 0; i < n; i++)
			rowProd[i].first = 1, rowProd[i].second = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				long double foo;
				scanf("%Lf", &foo);
				multiply(rowProd[i], transform(foo));
			}
		pair<long double, long long> dividend = rowProd[0];
		pair<long double, long long> divisor = dividend;
		for (int i = 1; i < n; i++)
			add(divisor, rowProd[i]);
		divide(dividend, divisor);
		show(dividend);
	}
	return 0;
}
