#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	set<int> s;
	deque<pair<string, int> > v;
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		string ch;
		cin >> ch;
		int val;
		cin >> val;
		if (ch[0] == '+')
		{
			v.emplace_back(make_pair(ch, val));
			s.insert(val);
		}
		else
		{
			if (s.count(val))
				v.emplace_back(make_pair(ch, val));
			else
				v.emplace_front(make_pair(string("+"), val)), v.emplace_back(make_pair(ch, val)), s.insert(val);
		}
	}
	set<int> inthere;
	for (auto it: v)
	{
		if (it.first[0] == '+')
		{
			inthere.insert(it.second);
			ans = max(ans, (int) inthere.size());
		}
		else if (inthere.count(it.second))
			inthere.erase(inthere.find(it.second));
	}
	cout << ans << '\n';
	return 0;
}
