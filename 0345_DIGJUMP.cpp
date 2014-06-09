#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

int f(char c)
{
	return c - '0';
}

int main()
{
	char s[100005];
	scanf("%s", s);

	bool found = false;
	int i, idx, idxVal, addr, valAtAddr, jumps, len = strlen(s);
	vector<int> counterparts[10];
	vector<bool> done(10, false);
	queue<pair<int, int> > q;
	pair<int, int> rem;

	for (i = 0; i < len; i++)
		counterparts[f(s[i])].push_back(i);

	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		rem = q.front();
		q.pop();
		addr = rem.first; jumps = rem.second;
		valAtAddr = f(s[addr]);
		for (i = 0; i < counterparts[valAtAddr].size(); i++)
		{
			if (counterparts[valAtAddr][i] != addr)
			{
				q.push(make_pair(counterparts[valAtAddr][i], jumps + 1));
				if (counterparts[valAtAddr][i] == len - 1)
				{
					found = true;
					break;
				}
			}
		}
		done[valAtAddr] = true;

		if (addr > 0)
		{
			idx = addr - 1; idxVal = f(s[idx]);
			if (!done[idxVal])
				q.push(make_pair(idx, jumps + 1));
		}

		if (addr < len - 1)
		{
			idx = addr + 1; idxVal = f(s[idx]);
			if (!done[idxVal])
				q.push(make_pair(idx, jumps + 1));
			if (idx == len - 1)
			{
				found = true;
				break;
			}
		}

		if (found)
			break;
	}

	printf("%d\n", q.back().second);
	return 0;
}
