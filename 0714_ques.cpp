#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long inf = 1e15;

int main()
{
	optimizeIO();
	long long n, k;
	cin >> n >> k;
	vector<long long> v(n, inf), isnum(n, 1);
	char s[11];
	for (long long i = 0; i < n; i++)
	{
		scanf("%s", s);
		if (s[0] != '?')
			sscanf(s, "%lld", &v[i]);
		else
			isnum[i] = 0;
	}
	return 0;
}
