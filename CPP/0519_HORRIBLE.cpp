#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int n, c;

LL T[400004], L[400004];

void upd(int v, int ds, int de, LL val)
{
	L[v] += val;
	T[v] += val * (de - ds);
}

void shiftFlag(int v, int ds, int de)
{
	int mid = (ds + de) / 2;
	upd(2 * v, ds, mid, L[v]);
	upd(2 * v + 1, mid, de, L[v]);
	L[v] = 0;
}

void update(int v, int s, int e, int ds, int de, LL val)
{
	if (s >= de or e <= ds or ds >= de)
		return;
	if (s <= ds and de <= e)
	{
		upd(v, ds, de, val);
		return;
	}
	shiftFlag(v, ds, de);
	int mid = (ds + de) / 2;
	update(2 * v, s, e, ds, mid, val);
	update(2 * v + 1, s, e, mid, de, val);
	T[v] = T[2 * v] + T[2 * v + 1];
}

LL query(int v, int s, int e, int ds, int de)
{
	if (s >= de or e <= ds or ds >= de)
		return 0;
	if (s <= ds and de <= e)
		return T[v];
	shiftFlag(v, ds, de);
	int mid = (ds + de) / 2;
	return query(2 * v, s, e, ds, mid) + query(2 * v + 1, s, e, mid, de);
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		memset(T, 0, sizeof(T));
		memset(L, 0, sizeof(L));
		int type, p, q;
		LL val;
		while (c--)
		{
			cin >> type >> p >> q;
			p--; q--;
			if (type == 0)
			{
				cin >> val;
				update(1, p, q + 1, 0, n, val);
			}
			else
				cout << query(1, p, q + 1, 0, n) << '\n';
		}
	}
	return 0;
}
