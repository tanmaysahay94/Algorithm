#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define OPEN 0
#define CLOSED 1

int main()
{
	optimizeIO();
	int n, k;
	cin >> n >> k;
	vector<int> s(n + 1), ptr(k), state(k, CLOSED);
	vector<vector<int> > jt;
	for (int i = 0; i < k; i++)
	{
		int sz;
		cin >> sz;
		vector<int> foo(sz);
		ptr[i] = 0;
		for (int j = 0; j < sz; j++)
		{
			cin >> foo[j];
			s[foo[j]] = i;
		}
		jt.push_back(foo);
	}
	long long ans = 0;
	int curr = 1, next = 2;
	while (next <= n)
	{
		int lcurr = s[curr];
		int lnext = s[next];
		if (lcurr == lnext)
		{
			ptr[lcurr]++;
			if (state[lcurr] == OPEN)
				ans++;
		}
		else
		{
			if (state[lcurr] == CLOSED and ptr[lcurr] + 1 < (int) jt[lcurr].size())
			{
				state[lcurr] = OPEN, ans += (int) jt[lcurr].size() - ptr[lcurr] - 1;
				ptr[lcurr]++;
			}
			if (state[lnext] == CLOSED and ptr[lnext] + 1 < (int) jt[lnext].size())
			{
				state[lnext] = OPEN, ans += (int) jt[lnext].size() - ptr[lnext] - 1;
			}
			ans++;
		}
		curr++;
		next++;
	}
	cout << ans;
	return 0;
}
