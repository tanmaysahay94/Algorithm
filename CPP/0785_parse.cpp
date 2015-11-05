#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<int, string> mp;
string space(" ");

void f(long long n)
{
	string ret;
	int cnt = 0;
	while (n)
	{
		string s;
		long long h, v = n%1000;
		if (v/100)
			s += mp[v/100] + string("Hundred");
		h = n%100;
		if (mp.find(h) != mp.end())
			s += mp[h];
		else
			s += mp[10*(h/10)] + mp[h%10];
		if (n % 1000)
		{
			if (cnt == 1)
				s += string("Thousand");
			else if (cnt == 2)
				s += string("Million");
			else if (cnt == 3)
				s += string("Billion");
			else if (cnt == 4)
				s += string("Trillion");
		}
		cnt++;
		ret = s + ret;
		n /= 1000;
	}
	for (int i = 0; i < (int) ret.length(); i++)
	{
		cout << ret[i];
		if (i > 0 and i + 1 < (int) ret.length() and ret[i + 1] >= 'A' and ret[i + 1] <= 'Z')
			cout << " ";
	}
	cout << endl;
}

int main()
{
	optimizeIO();
	mp[1] = string("One");
	mp[2] = string("Two");
	mp[3] = string("Three");
	mp[4] = string("Four");
	mp[5] = string("Five");
	mp[6] = string("Six");
	mp[7] = string("Seven");
	mp[8] = string("Eight");
	mp[9] = string("Nine");
	mp[10] = string("Ten");
	mp[11] = string("Eleven");
	mp[12] = string("Twelve");
	mp[13] = string("Thirteen");
	mp[14] = string("Fourteen");
	mp[15] = string("Fifteen");
	mp[16] = string("Sixteen");
	mp[17] = string("Seventeen");
	mp[18] = string("Eighteen");
	mp[19] = string("Nineteen");
	mp[20] = string("Twenty");
	mp[30] = string("Thirty");
	mp[40] = string("Forty");
	mp[50] = string("Fifty");
	mp[60] = string("Sixty");
	mp[70] = string("Seventy");
	mp[80] = string("Eighty");
	mp[90] = string("Ninety");
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		f(n);
	}
	return 0;
}
