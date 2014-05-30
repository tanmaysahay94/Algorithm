#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> v;
vector<int> coins(1000000, 2147483647);
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cin >> s;
	coins[0] = 0;
	for (int i = 1; i <= s; i++)		//bottom-up approach
		for (int j = 0; j < n; j++)			//iterate through vector, v
		{
			if (v[j] > i)
			{
				if (coins[i] == 2147483647)
					coins[i] = 0;
				break;
			}
			else if (v[j] == i)
			{
				coins[i] = 1;
				break;
			}
			else if (coins[i - v[j]])
				coins[i] = min(coins[i], coins[i - v[j]] + 1);
		}
	for (int i = s; i >= 0; i--)
		if (coins[i] == 2147483647 || coins[i] < 0)
			coins[i] = 0;
	for (int i = 0; i <= s; i++)
		cout << i << ' ' << coins[i] << endl;
}
