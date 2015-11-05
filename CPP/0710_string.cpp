#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	string a, b;
	cin >> a >> b;
	int l = a.size() - 1;
	while (a[l] == 'z' and l > 0)
		a[l--] = 'a';
	if (l == 0 and a[0] == 'z')
		cout << "No such string\n";
	else
		a[l]++;
	if (a < b)
		cout << a;
	else
		cout << "No such string\n";
	return 0;
}
