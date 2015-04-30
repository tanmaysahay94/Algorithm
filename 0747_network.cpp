#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> degree;
int n, m;

int bus()
{
	int a(0), b(0);
	for (int i = 0; i < n; i++)
		if (degree[i] == 2)
			a++;
		else if (degree[i] == 1)
			b++;
	return (a == n - 2 and b == 2);
}

int star()
{
	int a(0), b(0);
	for (int i = 0; i < n; i++)
		if (degree[i] == n - 1)
			a++;
		else if (degree[i] == 1)
			b++;
	return (a == 1 and b == n - 1);
}

int ring()
{
	for (int i = 0; i < n; i++)
		if (degree[i] != 2)
			return false;
	return true;
}

int main()
{
	optimizeIO();
	cin >> n >> m;
	degree = vector<int> (n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		degree[a]++;
		degree[b]++;
	}
	if (bus())
		cout << "bus ";
	else if (ring())
		cout << "ring ";
	else if (star())
		cout << "star ";
	else
		cout << "unknown ";
	cout << "topology\n";
	return 0;
}
