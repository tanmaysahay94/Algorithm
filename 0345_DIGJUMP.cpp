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

int main()
{
	string s;
	int i, j, k, len, idx, jumps, idxVal, valAtAddr, addr;
	bool found = false;
	pair<int, int> rem;
	queue<pair<int, int> > working;
	vector<int> same[10];

	cin >> s;
	len = s.length();
	vector<bool> progress(len, false);

	for (i = 0; i < len; i++)
		same[s[i] - '0'].push_back(i);

	working.push(make_pair(0, 0));
	progress[0] = true;
	while (!working.empty())
	{
		rem = working.front();
		working.pop();
		idx = rem.first; jumps = rem.second;

		if (idx > 0)
			if (!progress[idx - 1])
			{
				progress[idx - 1] = true;
				working.push(make_pair(idx - 1, jumps + 1));
			}

		if (idx < len - 1)
		{
			if (!progress[idx + 1])
			{
				progress[idx + 1] = true;
				working.push(make_pair(idx + 1, jumps + 1));
			}
			if (idx + 1 == len - 1)
			{
				found = true;
				break;
			}
		}

		idxVal = s[idx] - '0';
		for (i = 0; i < same[idxVal].size(); i++)
		{
			addr = same[idxVal][i];
			if (!progress[addr])
				working.push(make_pair(addr, jumps + 1));
			if (addr == len - 1)
			{
				found = true;
				break;
			}
		}

		if (found)
			break;
	}
	cout << working.back().second << endl;
	return 0;
}
