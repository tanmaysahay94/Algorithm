#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<long long> mem;

int main()
{
	optimizeIO();
	long long n, m, val, ans = 0, fact = 1;
	cin >> n >> m;
	mem.resize(m);
	for (long long i = 1; i < m; i++)
	{
		fact = (fact * i) % m;
		mem[i] = fact;
	}
	for (int i = 0; i < n; i++)
	{
		long long tmp = 0;
		cin >> val;
		if (val < m - 1)
			tmp = mem[val + 1];
		tmp -= 1;
		long long sahay;
		if (val % 2 == 0)
		{
			sahay = (val/2) % m;
			sahay = (sahay * (val % m)) % m;
			sahay = (sahay * ((val + 1) % m)) % m;
		}
		else
		{
			sahay = ((val + 1)/2) % m;
			sahay = (sahay * (val % m)) % m;
			sahay = (sahay * (val % m)) % m;
		}
		tmp = (tmp + sahay) % m;
		if (tmp < 0)
			tmp += m;
		ans = (ans + tmp) % m;
	}
	cout << ans << endl;
	return 0;
}
