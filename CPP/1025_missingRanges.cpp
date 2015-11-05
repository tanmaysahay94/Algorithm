#include <bits/stdc++.h>

using namespace std;

void print(int a, int b)
{
	if (a == b)
		cout << a << endl;
	else
		cout << a << "-" << b << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int start = 0;
	int prev = 0;
	bool printAtEnd = true;
	for (int i = 0; i < n; i++)
	{
		int curr = v[i];
		if (curr == prev or curr == prev + 1)
		{
			prev = curr;
			if (i == n - 1)
				printAtEnd = false;
			continue;
		}
		if (start)
			start = prev + 1;
		prev = curr - 1;
		print(start, prev);
		start = prev = curr;
	}
	if (not printAtEnd)
		print(start, prev);
	if (v[n - 1] != 100)
		print(v[n - 1] + 1, 100);
	return 0;
}
