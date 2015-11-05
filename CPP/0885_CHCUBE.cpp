#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool isOdd(int n)
{
	return (n&1);
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		bool found = false;
		vector<string> v(6);
		for (int i = 0; i < 6; i++)
			cin >> v[i];
		for (int i = 0; i < 6 and not found; i++)
			for (int j = i + 1; j < 6 and not found; j++)
			{
				if ((isOdd(i) and j + 1 == i) or (not isOdd(i) and j - 1 == i))
					continue;
				if (v[i] == v[j])
					for (int k = j + 1; k < 6 and not found; k++)
					{
						if ((not isOdd(j) and k - 1 == j) or (isOdd(j) and k + 1 == j))
							continue;
						if (v[j] == v[k])
							found = 1;
					}
			}
		if (found)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
