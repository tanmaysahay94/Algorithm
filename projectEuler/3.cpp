#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> is(1111111, 1);
set<long long> primes;

void init()
{
	is[0] = is[1] = 0;
	for (int i = 2; i < 1111111; i++)
	{
		if (is[i])
		{
			primes.insert(i);
			for (int j = 2*i; j < 1111111; j += i)
				is[j] = 0;
		}
	}
}

bool isPrime(long long n)
{
	set<long long>::iterator sit;
	bool ret = true;
	for (sit = primes.begin(); ret and sit != primes.end(); sit++)
		if (n % (*sit) == 0)
			ret = false;
	return ret;
}

int __main()
{
	optimizeIO();
	init();
	int t;
	cin >> t;
	while (t--)
	{
		long long ans = -1;
		long long n;
		cin >> n;
		if (primes.count(n))
		{
			cout << n << endl;
			continue;
		}
		set<long long>::iterator sit;
		for (sit = primes.begin(); sit != primes.end(); sit++)
		{
			long long val = *sit;
			if (n % val == 0)
			{
				ans = max(ans, val);
				if (isPrime(n/val))
				{
					ans = max(ans, n/val);
					primes.insert(n/val);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

int main()
{
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long nn = n;
		long long lf = 0;
		long long counter = 2;
		while (counter * counter <= nn)
		{
			if (nn % counter == 0)
			{
				nn = nn / counter;
				lf = counter;
			}
			else
				counter++;
		}
		if (nn > lf)
			lf = nn;
		cout << lf << endl;
	}
	return 0;
}
