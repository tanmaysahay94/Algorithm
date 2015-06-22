#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

short n;
vector<short> x(2001), y(2001);
int ans;

int main()
{
	optimizeIO();
	cin >> n;
	for (short i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (short i = 0; i < n; i++)
		for (short j = i + 1; j < n; j++)
			for (short k = j + 1; k < n; k++)
				if ((y[k] - y[j]) * (x[j] - x[i]) != (y[j] - y[i]) * (x[k] - x[j]))
					ans++;
	printf("%d\n", ans);
	return 0;
}
