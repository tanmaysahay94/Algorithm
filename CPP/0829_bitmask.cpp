#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string to_string(int val)
{
	if (val == 0)
		return string("0");
	string ret;
	while (val)
	{
		ret += (val % 10) + '0';
		val /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	optimizeIO();
	string s;
	cin >> s;
	int n = s.length();
	vector<string> valid;
	string ans;
	for (int i = 0; i < 125; i++)
		valid.push_back(to_string(8 * i));
	bool found = false;
	for (int i = 0; not found and i < 125; i++)
	{
		int j = 0, k = 0;
		for (; j < (int) valid[i].length() and k < n; k++)
		{
			if (valid[i][j] == s[k])
			{
				j++;
				if (j == (int) valid[i].length())
					found = true, ans = valid[i];
			}
		}
	}
	if (found)
		cout << "YES\n" << ans << endl;
	else
		cout << "NO\n";
	return 0;
}
