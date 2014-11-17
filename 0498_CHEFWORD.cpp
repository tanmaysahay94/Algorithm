#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL t, n, k, len;
string s, in;
vector<vector<double> > prob(26, vector<double> (26, 0));
map<string, bool> present;
vector<string> out;
double ans, cur;

void fastPow(LL n)
{
	vector<vector<double> > ret(26, vector<double> (26, 0));
	for (int i = 0; i < 26; i++)
		ret[i][i] = 1;
	while (n)
	{
		if (n & 1)
		{
			vector<vector<double> > temp(26, vector<double> (26, 0));
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++)
					for (int k = 0; k < 26; k++)
						temp[i][j] += ret[i][k] * prob[k][j];
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++)
					ret[i][j] = temp[i][j];
		}
		vector<vector<double> > temp(26, vector<double> (26, 0));
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				for (int k = 0; k < 26; k++)
					temp[i][j] += prob[i][k] * prob[k][j];
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				prob[i][j] = temp[i][j];
		n >>= 1;
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			prob[i][j] = ret[i][j];
}

int main()
{
	SLL(t);
	while (t--)
	{
		out.resize(0);
		present.clear();
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				prob[i][j] = 0;

		SLL(n); SLL(k);

		cin >> s;
		len = s.length();

		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				scanf("%lf", &prob[i][j]);

		for (int i = 0; i < n; i++)
		{
			cin >> in;
			if (in.length() == len and present.find(in) == present.end())
			{
				present[in] = true;
				out.pb(in);
			}
		}

		fastPow(k);

		ans = 0;
		for (int i = 0; i < out.size(); i++)
		{
			cur = 1;
			for (int j = 0; j < len; j++)
				cur *= prob[s[j] - 'a'][out[i][j] - 'a'];
			ans += cur;
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}
