#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<double> p;
int n;

double ans()
{
	double ans = p[0];
	double sum = p[0]/(1 - p[0]);
	double prod = 1 - p[0];
	for (int i = 1; i < n; i++)
	{
		prod *= (1 - p[i]);
		sum += p[i] / (1 - p[i]);
		ans = max(ans, prod * sum);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	p.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i]);
	sort(p.rbegin(), p.rend());
	printf("%.9lf\n", ans());
	return 0;
}
