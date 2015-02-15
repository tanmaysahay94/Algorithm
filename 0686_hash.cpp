#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long N = 6e5 + 5;
const long long mod = 1e16 + 7;
long long p[N] = {1};
set<long long> present;
string s;

long long getHash()
{
	long long hash = 0;
	for (int i = 0; s[i]; i++)
		hash = (hash + (s[i] - 'a' + 1) * p[i]) % mod;
	return hash;
}

bool check()
{
	long long hash = getHash();
	for (int i = 0; s[i]; i++)
	{
		long long v = s[i] - 'a' + 1;
		for (int j = 1; j < 4; j++)
		{
			if (v != j)
			{
				long long temp = (hash - v * p[i]) % mod + mod;
				temp = (temp + j * p[i]) % mod;
				if (present.count(temp))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	optimizeIO();
	for (int i = 1; i < N; i++)
		p[i] = (p[i - 1] * 4) % mod;
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		cin >> s;
		present.insert(getHash());
	}
	while (m--)
	{
		cin >> s;
		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
