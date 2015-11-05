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
	int na, nb;
	cin >> na >> nb;
	int k, m;
	cin >> k >> m;
	vector<int> A(na), B(nb);
	for (int i = 0; i < na; i++)
		cin >> A[i];
	for (int i = 0; i < nb; i++)
		cin >> B[i];
	k--, m--;
	int v1 = A[k];
	int v2 = B[nb - m - 1];
	if (v1 < v2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
