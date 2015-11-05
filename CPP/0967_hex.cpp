#include <bits/stdc++.h>

using namespace std;

string int2bstr(int n)
{
	string s;
	while (n)
	{
		s.push_back(n%2 + '0');
		n >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

int str2int(string& s)
{
	int n = 0;
	for (auto ss: s)
		n = 10 * n + ss - '0';
	return n;
}

int f(int i)
{
	string s = int2bstr(i);
	return str2int(s);
}

int main()
{
	vector<int> pre;
	pre.push_back(0);
	for (int i = 1; i < 1024; i++)
		pre.push_back(f(i));
	int n;
	cin >> n;
	int idx = lower_bound(pre.begin(), pre.end(), n) - pre.begin();
	if (pre[idx] != n)
		idx--;
	cout << idx;
	return 0;
}
