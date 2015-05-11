#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<bool> is(1111111, true);
vector<int> primes;

void init()
{
	is[0] = is[1] = 0;
	for (int i = 2; i < 1111111; i++)
	{
		if (is[i])
		{
			primes.push_back(i);
			for (int j = 2 * i; j < 1111111; j += i)
				is[j] = 0;
		}
	}
}

int f(int n)
{
	int ret = 1;
	for (int i = 0; n > 1 and i < (int) primes.size(); i++)
	{
		if (n % primes[i] == 0)
		{
			int cnt = 0;
			while (n % primes[i] == 0)
			{
				cnt++;
				n /= primes[i];
			}
			ret *= cnt+1;
		}
	}
	return ret;
}

int main()
{
	init();
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 1;
		int toAdd = 2;
		while (f(ans) <= n)
		{
			ans += toAdd;
			toAdd++;
		}
		cout << ans << endl;
	}
	return 0;
}
