#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> sieve(1001, 1);
vector<int> ans1, ans2;

string f(int i)
{
	string ret;
	while (i)
	{
		ret += (i % 10) + '0';
		i /= 10;
	}
	return ret;
}

bool isPalin(string s)
{
	int len = s.length();
	bool ret = true;
	for (int i = 0; ret and i < len/2; i++)
		if (s[i] != s[len - i - 1])
			ret = false;
	return ret;
}

bool check1(int i)
{
	long long sum = 0;
	while (i)
	{
		sum += (i%10) * (i%10);
		i /= 10;
	}
	if (sum > 9)
		return check1(sum);
	if (sum == 1)
		return true;
	return false;
}

bool check2(int i)
{
	string s = f(i);
	return isPalin(s);
}

void init()
{
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i < 1001; i++)
	{
		if (sieve[i])
		{
			if (check1(i))
				ans1.push_back(i);
			if (check2(i))
				ans2.push_back(i);
			for (int j = 2 * i; j < 1001; j += i)
				sieve[j] = 0;
		}
	}
}

void show(vector<int>& v)
{
	cout << v.size() << endl;
	for (int i = 0; i < (int) v.size(); i++, cout << ' ')
		cout << v[i];
	cout << endl;
}

int main()
{
	optimizeIO();
	init();
	show(ans1);
	show(ans2);
	return 0;
}
