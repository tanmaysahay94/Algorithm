#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <string.h>
#include <cmath>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int t, n, m, i, j, k;
	cin >> t;
	while (t--)
	{
		int pair = 0;
		cin >> n;
		vector<int> student(n);
		for (i = 0; i < n; i++)
			cin >> student[i];
		cin >> m;
		vector<int> faculty(m);
		for (i = 0; i < m; i++)
			cin >> faculty[i];
		vector<int> total(n + m);
		for (i = 0, j = 0, k = 0; i < n + m && j < n && k < m; i++)
		{
			if (student[j] <= faculty[k])
			{
				if (student[j] == faculty[k])
					pair++;
				total[i] = student[j++];
			}
			else
				total[i] = faculty[k++];
		}
		while (j != n)
			total[i++] = student[j++];
		while (k != m)
			total[i++] = faculty[k++];
		cout << max(n - pair, m - pair) << endl;
	}
}
