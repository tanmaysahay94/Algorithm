#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ans = 0;
	long long n, d;
	cin >> n >> d;
	vector<long long> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	vector<long long> farthest(n);
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr < n and x[ptr] - x[i] <= d)
			ptr++;
		ptr--;
		farthest[i] = ptr;
	}
	for (int i = 0; i < n; i++)
	{
		long long l = i;
		long long r = farthest[i];
		long long dist = r - l;
		ans += (dist * (dist - 1)) / 2;
	}
	cout << ans;
	return 0;
}
