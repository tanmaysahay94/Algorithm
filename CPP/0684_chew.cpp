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
	string num;
	cin >> num;
	for (int i = 0; num[i]; i++)
		num[i] = min(9 - num[i] + '0', num[i] - '0') + '0';
	if (num[0] == '0')
		num[0] = '9';
	cout << num << endl;
	return 0;
}
