#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct cmp
{
	bool operator() (const int& a, const int& b)
	{
		return a > b;
	}
};

multiset<int> m;
priority_queue<int> pmax;
priority_queue<int, vector<int>, cmp> pmin;

int main()
{
	optimizeIO();
	int q;
	cin >> q;
	while (q--)
	{
		int t, a;
		cin >> t;
		if (t == 1)
		{
			cin >> a;
			pmax.push(a);
			pmin.push(a);
			m.insert(a);
		}
		else if (t == 2)
		{
			cin >> a;
			if (m.count(a) == 0)
				cout << "-1\n";
			else
				m.erase(m.find(a));
		}
		else if (t == 3)
		{
			if (m.size() == 0)
				cout << "-1\n";
			else
			{
				while (not pmax.empty() and m.count(pmax.top()) == 0)
					pmax.pop();
				if (pmax.empty())
					cout << "-1\n";
				else
					cout << pmax.top() << '\n';
			}
		}
		else if (t == 4)
		{
			if (m.size() == 0)
				cout << "-1\n";
			else
			{
				while (not pmin.empty() and m.count(pmin.top()) == 0)
					pmin.pop();
				if (pmin.empty())
					cout << "-1\n";
				else
					cout << pmin.top() << '\n';
			}
		}
	}
	return 0;
}
