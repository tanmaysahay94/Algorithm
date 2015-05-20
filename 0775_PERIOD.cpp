#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> table;

void build_kmp(string& s)
{
	table[0] = table[1] = 0;
	for (int i = 2; i < (int) table.size(); i++)
	{
		int j = table[i - 1];
		for (;;)
		{
			if (s[j] == s[i - 1])
			{
				table[i] = j + 1;
				break;
			}
			else if (j == 0)
			{
				table[i] = 0;
				break;
			}
			else
				j = table[j];
		}
		if (table[i] and i % (i - table[i]) == 0)
			printf("%d %d\n", i, i / (i - table[i]));
	}
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	for (int TT = 1; TT <= t; TT++)
	{
		int n;
		string s;
		cin >> n >> s;
		table.resize(n + 1);
		printf("Test case #%d\n", TT);
		build_kmp(s);
		printf("\n");
	}
	return 0;
}
