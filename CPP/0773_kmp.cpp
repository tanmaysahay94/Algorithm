#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void build_KMP(string& p, vector<int>& t)
{
	// t[i] gives the length of the longest prefix suffix that's not the prefix p[0...i-1] itself
	t[0] = t[1] = 0;
	for (int i = 2; i <= (int) t.size(); i++)
	{
		int j = t[i - 1];
		for (;;)
		{
			if (p[j] == p[i - 1])
			{
				t[i] = j + 1;
				break;
			}
			if (j == 0)
			{
				t[i] = 0;
				break;
			}
			j = t[j];
		}
	}
}

int kmp(string& p, string& t, vector<int>& f)
{
	int m = p.length();
	int n = t.length();
	int i(0), j(0);
	// i - in pattern
	// j - in text
	for (;;)
	{
		if (j == n)
			return n;
		if (t[j] == p[i])
		{
			i++;
			j++;
			if (i == m)
				return m;
		}
		else if (i > 0)
			i = f[i];
		else
			j++;
	}
}

int main()
{
	optimizeIO();
	string pattern, text;
	cin >> pattern >> text;
	vector<int> table(pattern.length() + 1);
	build_KMP(pattern, table);
	int location = kmp(pattern, text, table);
	if (location == (int)text.length()) cout << "Not found\n";
	else cout << "Match starts at location " <<location<<endl;
	return 0;
}
