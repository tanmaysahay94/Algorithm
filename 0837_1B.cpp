#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool isChar(char a)
{
	return (a >= 'A' and a <= 'Z');
}

bool isNum(char a)
{
	return (a >= '0' and a <= '9');
}

bool same(char a, char b)
{
	if (isChar(a) and isChar(b))
		return true;
	if (isNum(a) and isNum(b))
		return true;
	return false;
}

bool type1(string s)
{
	int n = s.size();
	int change = 0;
	for (int i = 1; i < n; i++)
		if (not same(s[i], s[i - 1]))
			change++;
	return (change == 1);
}

string toString(long long num)
{
	if (num == 0)
		return string("0");
	string ret;
	while (num)
	{
		ret += (num % 10) + '0';
		num /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string toAlpha(long long num)
{
	string ret;
	while (num)
	{
		int md = num % 26;
		if (md == 0)
			ret += 'Z', num--;
		else
			ret += md - 1 + 'A';
		num /= 26;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string toType2(string s)
{
	string firstPart = "R";
	string secondPart = "C";
	int n = s.size();
	int i = 0;
	long long num = 0;
	while (isChar(s[i]))
		i++;
	for (int ii = 0; ii < i; ii++)
		num = 26 * num + (s[ii] - 'A' + 1);
	secondPart += toString(num);
	for (int ii = i; ii < n; ii++)
		firstPart.push_back(s[ii]);
	return firstPart + secondPart;
}

string toType1(string s)
{
	int n = s.size();
	string secondPart;
	int i = 1;
	while (s[i] != 'C')
	{
		if (s[i] != 'C')
			secondPart.push_back(s[i]);
		else
			break;
		i++;
	}
	long long num = 0;
	for (int ii = i + 1; ii < n; ii++)
		num = 10 * num + (s[ii] - '0');
	return toAlpha(num) + secondPart;
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (type1(s))
			cout << toType2(s) << endl;
		else
			cout << toType1(s) << endl;
	}
	return 0;
}
