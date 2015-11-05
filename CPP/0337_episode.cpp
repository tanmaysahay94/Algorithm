#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, e;
	cin >> n;
	vector<int> v(n, 0);
	for (i = 0; i < n - 1; i++)
	{
		cin >> e;
		v[e - 1] = 1;
	}
	for (i = 0; i < n; i++)
		if (!v[i])
		{
			cout << i + 1;
			return 0;
		}
}
