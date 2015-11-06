#include <bits/stdc++.h>

using namespace std;

vector<int> build_kmp(string& text)
{
	int n = text.size();
	vector<int> F(n + 1);
	F[0] = F[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int j = F[i - 1];
		for (;;)
		{
			if (text[j] == text[i - 1])
			{
				F[i] = j + 1;
				break;
			}
			if (j == 0)
			{
				F[i] = 0;
				break;
			}
			j = F[j];
		}
	}
	return F;
}

int main()
{
	string text;
	cin >> text;
	vector<int> F = build_kmp(text);
	int ans = F[text.size()];
	bool found = false;
	while (ans > 0)
	{
		for (int i = text.size() - 1; i > ans and not found; i--)
			found = F[i] >= ans;
		if (found)
			break;
		ans = F[ans];
	}
	if (found)
		cout << text.substr(0, ans);
	else
		cout << "Just a legend";
	return 0;
}
