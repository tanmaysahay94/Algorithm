#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e9 + 7;

long long powMod(long long a, long long b)
{
	long long ret = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	optimizeIO();
	long long n;
	string str;
	cin >> n >> str;
	map<char, long long> mp;
	for (int i = 0; str[i]; i++)
		mp[str[i]]++;
	long long pow = max(mp['A'], mp['T']);
	pow = max(pow, mp['C']);
	pow = max(pow, mp['G']);
	long long base = 0;
	if (pow == mp['A']) base++;
	if (pow == mp['T']) base++;
	if (pow == mp['C']) base++;
	if (pow == mp['G']) base++;
	cout << powMod(base, n) << endl;
	return 0;
}
