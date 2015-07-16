#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P2I;
typedef pair<int, P2I> P3I;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct cmp
{
	bool operator() (const P3I& a, const P3I& b)
	{
		if (a.first != b.first)
			return a.first > b.first;
		if (a.second.first != b.second.first)
			return a.second.first > b.second.first;
		return a.second.second > b.second.second;
	}
};

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> valid(n, 1);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		if (n == 1)
		{
			cout << "0\n";
			continue;
		}
		priority_queue<P3I, vector<P3I>, cmp> pq;
		for (int i = 1; i < n; i++)
			pq.push(make_pair(max(v[i], v[i - 1]), make_pair(i - 1, i)));
		long long ans = 0;
		while (not pq.empty())
		{
			P3I foo = pq.top(); pq.pop();
			while (not pq.empty() and not (valid[foo.second.first] and valid[foo.second.second]))
			{
				foo = pq.top();
				pq.pop();
			}
			int val = foo.first, left = foo.second.first, right = foo.second.second;
			ans += val;
			if (val == v[left])		// left index is still valid
			{
				valid[right] = 0;	// right is invalid
				while (right < n and not valid[right])
					right++;
				if (right < n)
					pq.push(make_pair(max(val, v[right]), make_pair(left, right)));	// a new valid pair is added
			}
			else
			{
				valid[left] = 0;
				while (left >= 0 and not valid[left])
					left--;
				if (left >= 0)
					pq.push(make_pair(max(val, v[left]), make_pair(left, right)));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
