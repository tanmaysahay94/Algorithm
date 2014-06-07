#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <functional>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int ans = 100005;
vector<int> address[10];
vector<int> smallest(100005, -1);

void jump(string& a, int currLoc, int val)	//input - string a, currLoc - points to curr index, val - no. of jumps
{
	if (currLoc == a.length() - 1)
	{
		ans = min(ans, val);
		return;
	}
	if (a[currLoc] == a[a.length() - 1])
	{
		ans = min(ans, val + 1);
		return;
	}
	if (currLoc > 1)
		jump(a, currLoc - 1, val + 1);
	if (currLoc < a.length())
		jump(a, currLoc + 1, val + 1);
	for (int i = 0; i < address[a[currLoc] - 48].size(); i++)
		jump(a, address[a[currLoc] - 48][i], val + 1);
}
int main()
{
	string s;
	int i, len;
	cin >> s;
	len = s.length();
	for (i = 0; i < len; i++)
		address[s[i] - 48].push_back(i);
	jump(s, 0, 0);
	cout << ans << endl;
}
