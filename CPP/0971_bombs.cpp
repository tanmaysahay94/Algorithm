#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	int adist = abs(a.first) + abs(a.second);
	int bdist = abs(b.first) + abs(b.second);
	return adist < bdist;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	sort(v.begin(), v.end(), cmp);
	vector<pair<pair<int, int>, char> > ans;
	for (auto V: v)
	{
		int x = V.first;
		int y = V.second;
		if (x > 0)
			ans.push_back(make_pair(make_pair(1, x), 'R'));
		else if (x < 0)
			ans.push_back(make_pair(make_pair(1, -x), 'L'));
		if (y > 0)
			ans.push_back(make_pair(make_pair(1, y), 'U'));
		else if (y < 0)
			ans.push_back(make_pair(make_pair(1, -y), 'D'));
		ans.push_back(make_pair(make_pair(2, 0), 'A'));
		if (x > 0)
			ans.push_back(make_pair(make_pair(1, x), 'L'));
		else if (x < 0)
			ans.push_back(make_pair(make_pair(1, -x), 'R'));
		if (y > 0)
			ans.push_back(make_pair(make_pair(1, y), 'D'));
		else if (y < 0)
			ans.push_back(make_pair(make_pair(1, -y), 'U'));
		ans.push_back(make_pair(make_pair(3, 0), 'A'));
	}
	cout << ans.size() << endl;
	for (auto A: ans)
	{
		int f = A.first.first;
		int s = A.first.second;
		char ch = A.second;
		if (f == 2 or f == 3)
			printf("%d\n", f);
		else
			printf("%d %d %c\n", f, s, ch);
	}
	return 0;
}
