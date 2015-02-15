#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e9 + 7;
long long mem[1801][301][10];

long long calc(long long r, long long b, long long l)
{
	if (l < 0)
		return 0;
	if (r == 0 and b == 0)
		return 1;
	if (r < 0 or b <= 0 or r > 6 * b)
		return 0;
	if (mem[r][b][l] != -1)
		return mem[r][b][l];
	long long ans = 0;
	if (l > 0)
		ans += calc(r, b - 1, l - 1);
	ans += calc(r, b - 1, l);
	ans += calc(r - 4, b - 1, l);
	ans += calc(r - 6, b - 1, l);
	ans %= mod;
	mem[r][b][l] = ans;
	return ans;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	memset(mem, -1, sizeof(mem));
	while (t--)
	{
		long long r, b, l;
		cin >> r >> b >> l;
		if (r > 6 * b or (r & 1))
			cout << 0 << endl;
		else
			cout << calc(r, b, l) << endl;
	}
	return 0;
}
