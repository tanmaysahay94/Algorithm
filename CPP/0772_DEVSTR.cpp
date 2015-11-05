#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string s;

void inline flip(int i)
{
	if (s[i] == '0') s[i] = '1';
	else s[i] = '0';
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k, ans(0);
		cin >> n >> k;
		string S;
		cin >> s;
		if (k == 1)
		{
			string S1, S2;
			for (int i = 0; i < n; i++)
				if (i & 1)
					S1.push_back('0'), S2.push_back('1');
				else
					S1.push_back('1'), S2.push_back('0');
			long long ans1(0), ans2(0);
			for (int i = 0; i < n; i++)
				ans1 += s[i] != S1[i], ans2 += s[i] != S2[i];
			if (ans1 < ans2) ans = ans1, S = S1;
			else ans = ans2, S = S2;
		}
		else
		{
			for (int i = 0; i < n;)
			{
				int j = i, cnt;
				while (j < n and s[j] == s[i])
					j++;
				cnt = (j - i)/(k + 1);
				ans += cnt;
				for (int l = 0, pos = i + k; l < cnt; l++, pos += k + 1)
					flip(pos);
				if (cnt * (k + 1) == j - i)
					flip(j - 1), flip(j - 2);
				i = j;
			}
			S = s;
		}
		cout << ans << '\n' << S << '\n';
	}
	return 0;
}
