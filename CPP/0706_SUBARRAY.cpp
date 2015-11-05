#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxn = 1e5 + 7;
char ch[maxn];
long long in[maxn], sum[maxn], open[maxn], dp[maxn];

char opp(char c)
{
	if (c == ')') return '(';
	if (c == '>') return '<';
	if (c == '}') return '{';
	if (c == ']') return '[';
	return '.';
}

void solveTestCase()
{
	long long ans = 0;
	ch[0] = '!';
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++)
		open[i] = 0;
	scanf("%s", ch + 1);
	for (int i = 1; i <= n; i++)
		scanf("%lld\n", &in[i]);
	for (int i = 1; i <= n; i++)
		sum[i] = in[i] + sum[i - 1];
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n; i++)
		if (ch[s.top()] == opp(ch[i]))
		{
			open[i] = s.top();
			s.pop();
		}
		else
			s.push(i);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 0;
		if (open[i])
			dp[i] = max(sum[i] - sum[open[i] - 1] + dp[open[i] - 1], dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
}

int main()
{
/*	optimizeIO();*/
	int t;
	scanf("%d", &t);
	while (t--)
		solveTestCase();
	return 0;
}
