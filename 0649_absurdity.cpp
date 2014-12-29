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

template <class T> void show_arr(T &a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

template <class T> void show_vec(T &v)
{
	for (int i = 0; i < (int) v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int main()
{
	LL n, k;
	cin >> n >> k;
	VLL v(n + 1), pre(n + 1), start(n + 1), end(n + 1);
	vector<PLL> dpStart(n + 1, mp(0, 0)), dpEnd(n + 1, mp(0, 0));
	for (LL i = 1; i <= n; i++)
	{
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
	}
	for (LL i = k; i <= n; i++)
		end[i] = pre[i] - pre[i-k];
	for (LL i = n - k + 1; i >= 1; i--)
		start[i] = pre[i+k-1] - pre[i-1];
	dpEnd[k].f = end[k], dpEnd[k].s = 1;
	for (LL i = k; i < n; i++)
		if (end[i+1] < dpEnd[i].f)
			dpEnd[i+1] = dpEnd[i];
		else
			dpEnd[i+1].f = end[i+1], dpEnd[i+1].s = i - k + 2;
	dpStart[n-k+1].f = start[n-k+1], dpStart[n-k+1].s = n-k+1;
	for (LL i = n - k; i >= 1; i--)
		if (start[i] < dpStart[i+1].f)
			dpStart[i] = dpStart[i+1];
		else if (start[i] == dpStart[i+1].f)
		{
			dpStart[i] = dpStart[i+1];
			dpStart[i].s = i;
		}
		else
		{
			dpStart[i].f = start[i];
			dpStart[i].s = i;
		}
	LL a, b, ans = 0;
	for (LL i = k; i <= n - k; i++)
		if (ans < dpEnd[i].f + dpStart[i+1].f)
		{
			ans = dpEnd[i].f + dpStart[i+1].f;
			a = dpEnd[i].s, b = dpStart[i+1].s;
		}
		else if (ans == dpEnd[i].f + dpStart[i+1].f)
			a = min(a, dpEnd[i].s), b = min(b, dpStart[i+1].s);
	cout << a << ' ' << b << endl;
	return 0;
}
