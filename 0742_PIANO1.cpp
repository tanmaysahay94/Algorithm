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
	long long t;
	cin >> t;
	while (t--)
	{
		long long len(0), n;
		string s;
		cin >> s >> n;
		n *= 12;
		for (int i = 0; s[i]; i++)
			if (s[i] == 'S')
				len += 1;
			else
				len += 2;
		long long k = (n - 1)/len;
		cout << k * n - (len * (k + 1) * k)/2 << endl;
	}
	return 0;
}
