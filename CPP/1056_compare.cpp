#include <bits/stdc++.h>

using namespace std;

double get(vector<double>& V, double b)
{
	double ret = 0;
	for (int i = 0; i < (int) V.size(); i++)
		ret = b * ret + V[i];
	return ret;
}

int main()
{
	int n;
	double bn;
	cin >> n >> bn;
	vector<double> V(n);
	for (int i = 0; i < n; i++)
		cin >> V[i];
	int m;
	double bm;
	cin >> m >> bm;
	vector<double> U(m);
	for (int i = 0; i < m; i++)
		cin >> U[i];
	double vn = get(V, bn);
	double vm = get(U, bm);
	if (vn == vm)
		cout << "=";
	else if (vn < vm)
		cout << "<";
	else
		cout << ">";
	return 0;
}
