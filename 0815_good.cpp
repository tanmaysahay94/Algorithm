#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int main()
{
	optimizeIO();
	string s;
	cin >> s;
	LL even(0), odd(0);
	LL preEven[2] = {0}, preOdd[2] = {0};
	for (int i = 0; i < (int) s.length(); i++)
	{
		odd++;
		int c = s[i] - 'a';
		if (i & 1)
		{
			odd += preOdd[c];
			even += preEven[c];
			preOdd[c]++;
		}
		else
		{
			odd += preEven[c];
			even += preOdd[c];
			preEven[c]++;
		}
	}
	cout << even << ' ' << odd << endl;
	return 0;
}
