#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e7 + 1;
const int maxn = 1e6 + 1;

vector<int> sieve(maxx, 1);
vector<int> prime;
vector<int> pre;
vector<int> cnt(maxx);

void init()
{
	pre.push_back(0);
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i < maxx; i++)
		if (sieve[i])
		{
			prime.push_back(i);
			int val = 0;
			for (int j = i; j < maxx; j += i)
			{
				sieve[j] = 0;
				val += cnt[j];
			}
			pre.push_back(val);
			sieve[i] = 1;
		}
	for (int i = 1; i < (int) pre.size(); i++)
		pre[i] += pre[i - 1];
	pre.push_back(pre[pre.size() - 1]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		cnt[val]++;
	}
	init();
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int i1 = lower_bound(prime.begin(), prime.end(), l) - prime.begin();
		int i2 = upper_bound(prime.begin(), prime.end(), r) - prime.begin();
		printf("%d\n", pre[i2] - pre[i1]);
	}
	return 0;
}
