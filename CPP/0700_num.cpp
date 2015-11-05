#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	vector<string> mp(10);
	mp[2] = string("2");
	mp[3] = string("3");
	mp[4] = string("322");
	mp[5] = string("5");
	mp[6] = string("53");
	mp[7] = string("7");
	mp[8] = string("7222");
	mp[9] = string("7332");
	int n;
	cin >> n;
	string str;
	cin >> str;
	string answer;
	for (int i = 0; str[i]; i++)
		answer += mp[str[i] - '0'];
	sort(answer.rbegin(), answer.rend());
	cout << answer << endl;
	return 0;
}
