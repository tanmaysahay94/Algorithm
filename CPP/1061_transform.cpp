#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> a(3), b(3);
	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) cin >> b[i];
	int extra = 0, req = 0;
	for (int i = 0; i < 3; i++)
		if (a[i] >= b[i])
			extra += (a[i] - b[i]) / 2;
		else
			req += (b[i] - a[i]);
	if (extra >= req)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
