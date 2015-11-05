#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	string s;
	cin >> s;
	long long m, idx, len = s.length();
	cin >> m;
	vector<long long> v(m + 1), rev(len);
	v[m] = len/2;
	for (long long i = 0; i < m; i++)
	{
		cin >> idx;
		v[i] = min(idx - 1, len - idx);
	}
	sort(v.begin(), v.end());
	int torev = 0;
	for (long long i = 1; i <= m; i++)
	{
		long long start = v[i - 1];
		long long end = v[i];
		torev ^= 1;
		for (long long j = start; j < end; j++)
			rev[j] = torev;
	}
	for (long long i = 0; i < len/2; i++)
		if (rev[i])
			swap(s[i], s[len - 1 - i]);
	cout << s << endl;
	return 0;
}
