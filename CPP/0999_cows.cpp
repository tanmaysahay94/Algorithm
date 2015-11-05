#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int main()
{
	vector<double> inc(maxn, 0);
	double cnt = 1;
	double sum = 0;
	vector<double> num;
	num.push_back(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			double x;
			int a;
			scanf("%d%lf", &a, &x);
			sum += a * x;
			inc[a] += x;
		}
		else if (type == 2)
		{
			double k;
			scanf("%lf", &k);
			num.push_back(k);
			cnt = num.size();
			sum += k;
		}
		else
		{
			cnt = num.size();
			sum -= num[cnt - 1];
			num.pop_back();
			sum -= inc[cnt];
			inc[cnt - 1] += inc[cnt];
			inc[cnt] = 0;
			cnt = num.size();
		}
		printf("%.6lf\n", sum / cnt);
	}
	return 0;
}
