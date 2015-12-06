#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL maxn = 1555;
string S, B;
LL power[maxn];
LL base = 37;
LL k;

int main()
{
	cin >> S >> B >> k;
	unordered_set<LL> cnt;
	power[0] = 1;
	for (int i = 1; i < maxn; i++)
		power[i] = base * power[i - 1];
	for (int i = 0; i < (int) S.size(); i++)
	{
		LL hash = 0, bad = 0;
		for (int j = i; j < (int) S.size(); j++)
		{
			hash += power[j - i] * (S[j] - 'a' + 1);
			if (B[S[j] - 'a'] == '0')
			{
				bad++;
				if (bad <= k)
					cnt.insert(hash);
			}
			else if (bad <= k)
				cnt.insert(hash);
			if (bad > k)
				break;
		}
	}
	cout << cnt.size();
	return 0;
}
