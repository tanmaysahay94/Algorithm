#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, m;
	cin >> n >> m;
	VLL wt(n + 1), sched(m), vis(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> wt[i];
	for (int i = 0; i < m; i++)
		cin >> sched[i];
	stack<LL> init;
	stack<LL> st;
	for (int i = 0; i < m; i++)
		if (!vis[sched[i]])
		{
			vis[sched[i]] = 1;
			init.push(sched[i]);
		}
	LL ans = 0;
	while (!init.empty())
	{
		st.push(init.top());
		init.pop();
	}
	for (int i = 0; i < m; i++)
	{
		while (st.top() != sched[i])
		{
			init.push(st.top());
			ans += wt[st.top()];
			st.pop();
		}
		LL tmp = st.top();
		st.pop();
		while (!init.empty())
		{
			st.push(init.top());
			init.pop();
		}
		st.push(tmp);
	}
	cout << ans << endl;
	return 0;
}
