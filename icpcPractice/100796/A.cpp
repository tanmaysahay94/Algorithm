#include <bits/stdc++.h>

using namespace std;

bool iszero(string a)
{
	for (auto aa: a)
		if (aa != '0')
			return false;
	return true;
}

int main()
{
	string a, b;
	cin >> a >> b;
	if (a.size() < b.size())
		swap(a, b);
	while (b.size() < a.size())
		b = '0' + b;
	for (int i = 0; i < (int) a.size(); i++)
	{
		int v1 = a[i] - '0';
		int v2 = b[i] - '0';
		a[i] = abs(v1 - v2) + '0';
	}
	if (iszero(a))
		cout << "0";
	else
	{
		int i = 0;
		while (a[i] == '0')
			i++;
		for (; i < (int) a.size(); i++)
			cout << a[i];
	}
	return 0;
}
