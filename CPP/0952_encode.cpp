#include <bits/stdc++.h>

using namespace std;

int main()
{
	string heart;
	heart.push_back('<');
	heart.push_back('3');
	int n;
	cin >> n;
	string req = heart;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		req += word;
		req += heart;
	}
	string msg;
	cin >> msg;
	int i = 0, j = 0;
	while (i < (int) req.size() and j < (int) msg.size())
	{
		if (req[i] == msg[j])
			i++;
		j++;
	}
	if (i == (int) req.size())
		puts("yes");
	else
		puts("no");
	return 0;
}
