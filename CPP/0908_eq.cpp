#include <bits/stdc++.h>

using namespace std;

char a[200005], b[200005];

bool bar(int as, int ae, int bs, int be)
{
	for (int i = as, j = bs; i <= ae and j <= be; i++, j++)
		if (a[i] != b[j])
			return false;
	return true;
}

bool foo(int as, int ae, int bs, int be)
{
	if ((ae - as + 1) & 1)
		return bar(as, ae, bs, be);
	int am = (as + ae) / 2;
	int bm = (bs + be) / 2;
	return (foo(as, am, bs, bm) and foo(am + 1, ae, bm + 1, be)) or (foo(as, am, bm + 1, be) and foo(am + 1, ae, bs, bm));
}

int main()
{
	scanf("%s%s", a, b);
	int n = strlen(a);
	if (foo(0, n - 1, 0, n - 1))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
