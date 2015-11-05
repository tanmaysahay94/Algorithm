#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define daen 0
#define stan 1
typedef long long LL;

bool f(LL n, LL k, LL even, LL odd)
{
	if (n == k)
	{
		if (odd & 1)
			return stan;
		else
			return daen;
	}
	LL step = n - k;
	if (odd <= step / 2)
		return daen;
	else if (even <= step / 2)
	{
		if (k & 1)
			return stan;
		return daen;
	}
	else
	{
		if (step & 1)
			return stan;
		return daen;
	}
}

int main()
{
	optimizeIO();
	LL n, ec(0), oc(0), k, val;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		if (val & 1)
			oc++;
		else
			ec++;
	}
	if (f(n, k, ec, oc))
		cout << "Stannis\n";
	else
		cout << "Daenerys\n";
	return 0;
}
