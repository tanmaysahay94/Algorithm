#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int cnt = 1;
	char curr = s[0];
	for (int i = 1; i < n; i++)
		if (s[i] != curr)
			curr = s[i], cnt++;
	cout << min(n, cnt + 2);
	return 0;
}
