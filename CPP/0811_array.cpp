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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> left(n), right(n);
	for (int i = 0; i < n; i++)
	{
		pq.push(make_pair(v[i], i));
		left[i] = i - 1;
		right[i] = i + 1;
	}
	long long rem = n - 2, val = 0;
	long long ans = 0;
	while (rem > 0)
	{
		rem--;
		pair<int, int> foo = pq.top(); pq.pop();
		if (left[foo.second] == -1 or right[foo.second] == n)
		{
			ans += (rem + 1) * (v[foo.second] - val);
			val = v[foo.second];
		}
		else
			ans += min(v[left[foo.second]], v[right[foo.second]]) - val;
		if (left[foo.second] != -1)
			right[left[foo.second]] = right[foo.second];
		if (right[foo.second] != n)
			left[right[foo.second]] = left[foo.second];
	}
	cout << ans << endl;
	return 0;
}
