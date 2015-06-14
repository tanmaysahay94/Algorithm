#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, q;
const LL maxn = 100100;

vector<LL> v(maxn);

struct node
{
	LL ans, start, end, precount, postcount;
};

vector<node> st(4 * maxn);

void merge(node& par, node& left, node& right, LL s, LL e)
{
	LL m = (s + e) >> 1;
	par.precount = left.precount;
	par.postcount = right.postcount;
	if (par.precount == m - s + 1)
		par.precount += right.precount;
	if (par.postcount == e - m)
		par.postcount += left.postcount;
	if (left.ans == 0 or right.ans == 0)
	{
		par.ans = 0;
		par.start = left.start;
		par.end = right.end;
		return;
	}
	if (left.ans == 1 and right.ans == 1)
	{
		par.ans = 1;
		if (left.end - left.start >= right.end - right.start)
		{
			par.start = left.start, par.end = left.end;
			if (left.end == m)
				par.end += right.precount;
		}
		else if (left.end - left.start < right.end - right.start)
		{
			par.start = right.start, par.end = right.end;
			if (right.start == m + 1)
				par.start -= left.postcount;
		}
		if (left.postcount + right.precount > par.end - par.start + 1)
		{
			par.start = m - left.postcount + 1;
			par.end = m + right.precount;
		}
		else if (left.postcount + right.precount == par.end - par.start + 1)
			if (m - left.postcount + 1 < par.start)
				par.start = m - left.postcount + 1, par.end = m + right.precount;
	}
	else if (left.ans == 1)
	{
		par.ans = 1;
		par.start = left.start;
		par.end = left.end;
		if (left.end == m)
			par.end += right.precount;
	}
	else if (right.ans == 1)
	{
		par.ans = 1;
		par.end = right.end;
		par.start = right.start;
		if (right.start == m + 1)
			par.start -= left.postcount;
	}
	else
	{
		if (left.ans <= right.ans)
			par.ans = left.ans, par.start = left.start, par.end = left.end;
		else
			par.ans = right.ans, par.start = right.start, par.end = right.end;
	}
}

void init(LL idx, LL s, LL e)
{
	if (s == e)
	{
		st[idx].ans = v[s];
		st[idx].start = s;
		st[idx].end = e;
		if (v[s] == 1)
			st[idx].precount = st[idx].postcount = 1;
		else
			st[idx].precount = st[idx].postcount = 0;
		return;
	}
	LL m = (s + e) >> 1;
	LL l = idx << 1;
	LL r = l | 1;
	init(l, s, m);
	init(r, m + 1, e);
	merge(st[idx], st[l], st[r], s, e);
}

void query(node& result, LL idx, LL s, LL e, LL a, LL b)
{
	if (a > b or a > e or b < s)
		return;
	if (s == a and e == b)
	{
		result = st[idx];
		return;
	}
	LL m = (s + e) >> 1;
	LL l = idx << 1;
	LL r = l | 1;
	if (b <= m)
		query(result, l, s, m, a, b);
	else if (a > m)
		query(result, r, m + 1, e, a, b);
	else
	{
		node left, right;
		query(left, l, s, m, a, m);
		query(right, r, m + 1, e, m + 1, b);
		merge(result, left, right, s, e);
	}
}

void update(LL idx, LL s, LL e, LL a, LL b)
{
	if (s == e and s == a)
	{
		v[s] = b;
		node tmp;
		tmp.ans = b;
		tmp.start = s;
		tmp.end = e;
		if (b == 1)
			tmp.precount = tmp.postcount = 1;
		else
			tmp.precount = tmp.postcount = 0;
		st[idx] = tmp;
		return;
	}
	LL m = (s + e) >> 1;
	LL l = idx << 1;
	LL r = l | 1;
	if (a <= m)
		update(l, s, m, a, b);
	else
		update(r, m + 1, e, a, b);
	merge(st[idx], st[l], st[r], s, e);
}

void show()
{
	printf("------------------\n");
	for (int i = 1; i < 10; i++)
		printf("s:%lld e:%lld ans:%lld pre:%lld post:%lld\n", st[i].start, st[i].end, st[i].ans, st[i].precount, st[i].postcount);
	printf("------------------\n");
}

int main()
{
	scanf("%lld%lld", &n, &q);
	for (LL i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	init(1, 0, n - 1);
	for (LL i = 0; i < q; i++)
	{
		LL t, a, b;
		scanf("%lld%lld%lld", &t, &a, &b);
		if (t == 1)
		{
			node result;
			query(result, 1, 0, n - 1, --a, --b);
			printf("%lld %lld %lld\n", result.ans, result.start + 1, result.end + 1);
		}
		else
			update(1, 0, n - 1, --a, b);
		show();
	}
	return 0;
}
