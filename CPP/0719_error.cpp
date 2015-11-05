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
	map<long long, long long> m1, m2, m3;
	int n, error, a1, a2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> error;
		m1[error]++;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> error;
		m2[error]++;
	}
	for (int i = 0; i < n - 2; i++)
	{
		cin >> error;
		m3[error]++;
	}
	map<long long, long long>::iterator it;
	for (it = m1.begin(); it != m1.end(); it++)
	{
		long long v = it->first;
		if (m1[v] - m2[v] == 1)
		{
			a1 = v;
			break;
		}
	}
	for (it = m2.begin(); it != m2.end(); it++)
	{
		long long v = it->first;
		if (m2[v] - m3[v] == 1)
		{
			a2 = v;
			break;
		}
	}
	cout << a1 << endl << a2 << endl;
	return 0;
}
