#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, i;
	vector<int> out;
	cin >> n >> k;
	if (n < k*3)
		cout << -1 << endl;
	else
	{
		i = 0;
		out.resize(n);
		for (int j = 1; j <= n; j++)
			out[j-1] = j;
		for (int j = 0; j < k; j++, i++)
			cout << out[j] << ' ';
		for (int j = k-1; j >= 0; j--, i++)
			cout << out[j] << ' ';
		for (int j = 1; j < k; j++, i++)
			cout << out[j] << ' ';
		cout << out[0] << ' ';
		i++;
		while (i < n)
		{
			int c = 0;
			do
			{
				cout << out[c] << ' ';
				c++; i++;
				if (i == n)
					break;
				if (c == k)
					c = 0;
			}while(c);
		}
	}
}
