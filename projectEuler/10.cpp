#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<bool> is(1111111, true);
vector<long long> primes;

void init()
{
	is[0] = is[1] = 0;
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
	vector<long long> presum;
	presum.push_back(primes[0]);
	for (int i = 1; i < (int) primes.size(); i++)
		presum.push_back(presum[presum.size() - 1] + primes[i]);
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		if (n == 1) {cout << n << endl;continue;}
		vector<long long>::iterator it = lower_bound(primes.begin(), primes.end(), n);
		int idx = it - primes.begin();
		if (primes[idx] > n) idx--;
		cout << presum[idx] << endl;
	}
	return 0;
}
