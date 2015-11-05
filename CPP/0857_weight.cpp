#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

bool works(LL base, LL val, bool ans)
{
	if (val == 0) return false;
	if (val == 1) return true;
	if (val % base == 0) ans = ans or works(base, val / base, ans);
	else if ((val - 1) % base == 0) ans = ans or works(base, (val - 1) / base, ans);
	else if ((val + 1) % base == 0) ans = ans or works(base, (val + 1) / base, ans);
	return ans;
}

int main()
{
	optimizeIO();
	LL w, m;
	cin >> w >> m;
	bool ans = false;
	if (works(w, m, ans)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
