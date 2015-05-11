#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<long long> primes;
vector<bool> is(1111111, true);

void init()
{
	is[0] = is[1] = false;
	for (long long i = 2; i < 1111111; i++)
	{
		if (is[i])
		{
			primes.push_back(i);
			for (long long j = 2 * i; j < 1111111; j += i)
				is[j] = 0;
		}
	}
}

int main()
{
	optimizeIO();
	init();
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << primes[n-1] << endl;
	}
	return 0;
}
