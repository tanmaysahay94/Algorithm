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

struct segTree {
	LL sum, count[3];
};
const LL MAX = 1 << 17;
LL v[111111];
segTree T[MAX<<1];

LL nc2(LL p) {
	return (p * (p - 1))/2;
}

LL ans(LL vec[3]) {
	return nc2(vec[0] + 1) + nc2(vec[1]) + nc2(vec[2]);
}

void update(LL node, LL start, LL end, LL idx, LL val)
{
	if (start == end and start == idx)
	{
		T[node].count[v[idx]%3]--;
		T[node].sum = v[idx] = val;
		T[node].count[val%3]++;
		return;
	}
	LL left = 2 * node;
	LL right = left + 1;
	LL mid = (start + end) >> 1;
	if (idx <= mid)
		update(left, start, mid, idx, val);
	else
		update(right, mid + 1, end, idx, val);
	T[node].sum = T[left].sum + T[right].sum;
	LL md = T[left].sum%3;
	LL tmp[3];
	if (md == 0)
		for (LL i = 0; i < 3; i++)
			tmp[i] = T[right].count[i];
	else if (md == 1)
	{
		tmp[0] = T[right].count[2];
		tmp[1] = T[right].count[0];
		tmp[2] = T[right].count[1];
	}
	else if (md == 2)
	{
		tmp[0] = T[right].count[1];
		tmp[1] = T[right].count[2];
		tmp[2] = T[right].count[0];
	}
	for (LL i = 0; i < 3; i++)
		T[node].count[i] = T[left].count[i] + tmp[i];
}

void init(LL node, LL start, LL end)
{
	if (start == end)
	{
		T[node].count[v[start]%3]++;
		T[node].sum = v[start];
		return;
	}
	LL left = 2 * node;
	LL right = left + 1;
	LL mid = (start + end) >> 1;
	init(left, start, mid);
	init(right, mid + 1, end);
	T[node].sum = T[left].sum + T[right].sum;
	LL md = T[left].sum%3;
	LL tmp[3];
	if (md == 0)
		for (LL i = 0; i < 3; i++)
			tmp[i] = T[right].count[i];
	else if (md == 1)
	{
		tmp[0] = T[right].count[2];
		tmp[1] = T[right].count[0];
		tmp[2] = T[right].count[1];
	}
	else if (md == 2)
	{
		tmp[0] = T[right].count[1];
		tmp[1] = T[right].count[2];
		tmp[2] = T[right].count[0];
	}
	for (LL i = 0; i < 3; i++)
		T[node].count[i] = T[left].count[i] + tmp[i];
}

void query(segTree& res, LL node, LL start, LL end, LL open, LL close)
{
	if (start == open and end == close)
	{
		res = T[node];
		return;
	}
	LL left = 2 * node;
	LL right = left + 1;
	LL mid = (start + end) >> 1;
	if (close <= mid)
		query(res, left, start, mid, open, close);
	else if (open > mid)
		query(res, right, mid + 1, end, open, close);
	else
	{
		segTree L, R;
		query(L, left, start, mid, open, mid);
		query(R, right, mid + 1, end, mid + 1, close);
		res.sum = L.sum + R.sum;
		LL md = L.sum%3;
		LL tmp[3];
		if (md == 0)
			for (LL i = 0; i < 3; i++)
				tmp[i] = R.count[i];
		else if (md == 1)
		{
			tmp[0] = R.count[2];
			tmp[1] = R.count[0];
			tmp[2] = R.count[1];
		}
		else if (md == 2)
		{
			tmp[0] = R.count[1];
			tmp[1] = R.count[2];
			tmp[2] = R.count[0];
		}
		for (LL i = 0; i < 3; i++)
			res.count[i] = L.count[i] + tmp[i];
	}
}

int main()
{
	LL n, m, type, p, q;
	sll(n); sll(m);
	string num;
	cin >> num;
	segTree res;
	for (int i = 0; i < n; i++)
		v[i] = num[i] - '0';
	init(1LL, 0LL, n - 1);
	while (m--)
	{
		sll(type); sll(p); sll(q);
		if (type == 1)
			update(1LL, 0LL, n - 1, --p, q);
		else
		{
			query(res, 1LL, 0LL, n - 1, --p, --q);
			printf("%lld\n", ans(res.count));
		}
	}
	return 0;
}
