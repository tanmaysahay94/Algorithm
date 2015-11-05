#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<vector<double> > pascal;

vector<vector<double> > generate(int A) {
	vector<vector<double> > sol;
	if (A == 0) {
		return sol;
	}
	vector<double> tmp; tmp.push_back(1);
	sol.push_back(tmp);
	double k = 1;
	for (int i = 1; i < A; i++) {
		vector<double> foo;
		k /= 2;
		foo.push_back(k);
		for (int j = 1; j < (int) sol[i - 1].size(); j++) {
			foo.push_back((sol[i - 1][j] + sol[i - 1][j - 1])/2);
		}
		foo.push_back(k);
		sol.push_back(foo);
	}
	return sol;
}

int main()
{
	pascal = generate(1001);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, val, cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &val);
			if (val == -1)
				cnt++;
		}
		vector<double> nthRow = pascal[cnt - 1];
		double sum = 0;
		for (LL i = 0; i < (int) nthRow.size(); i++)
		{
			double v = i + 1;
			double u = nthRow[i];
			sum += v * u;
		}
		printf("%.6lf\n", sum);
	}
	return 0;
}
