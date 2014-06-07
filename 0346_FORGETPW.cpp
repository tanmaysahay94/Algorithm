#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <bits/stdc++.h>
#include <stack>
#include <cstdlib>
#include <set>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool is_zero = true;
		int i, n, l, start, end, is_decimal = false;
		char c, p;
		string s;
		cin >> n;
		map<char, char> hash;
		for (i = 0; i < n; i++)
		{
			cin >> c >> p;
			hash[c] = p;
		}
		cin >> s;
		l = s.length();
		for (i = 0; i < l; i++)
			if (hash.find(s[i]) != hash.end())
				s[i] = hash[s[i]];
		for (i = 0; i < l; i++)
			if (s[i] > '0' && s[i] <= '9')
			{
				is_zero = false;
				break;
			}
		if (is_zero) cout << "0\n";
		else
		{
			start = 0; end = l - 1;
			if (s[start] == '-')
			{
				cout << "-";
				start++;
			}
			else if (s[start] == '+')
				start++;
			while (s[start] == '0') start++;
			for (i = end; i >= start; i--)
				if (s[i] == '.')
				{
					is_decimal = true;
					break;
				}
			if (is_decimal)
			{
				while (s[end] == '0') end--;
				if (s[end] == '.') end --;
			}
			for (i = start; i <= end; i++)
				cout << s[i];
			cout << endl;
		}
	}
	return 0;
}
