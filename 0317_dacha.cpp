#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i, n, m, curr, total = 0;
	cin >> n >> m;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	i = 0;
	while (i < n)
	{
		curr = 0;
		while (curr < m)
		{
			curr += v[i];
			if (curr <= m)
				i++;
		}
		total++;
	}
	cout << total << endl;
}
