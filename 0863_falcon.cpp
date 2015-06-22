#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

vector<vector<LL> > v(3001, vector<LL> (3001, 0));
vector<LL> a(3001, 0);

LL kadane(vector<LL>& array)
{
	LL max_so_far = LLONG_MIN;
	LL max_ending_here = 0;
	LL max_element = LLONG_MIN;
	for (int i = 0; i < (int) array.size(); i++)
	{
		max_ending_here = max(max_ending_here + array[i], 0LL);
		max_so_far = max(max_ending_here, max_so_far);
		max_element = max(max_element, array[i]);
	}
	if (max_so_far == 0)
		max_so_far = max_element;
	return max_so_far;
}

int main()
{
	optimizeIO();
	LL n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			v[i][j] = a[i] * a[j];
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		vector<LL> foo;
		for (int row = i, col = 0; row >= 0; row--, col++)
			foo.push_back(v[row][col]);
		ans = max(ans, kadane(foo));
	}
	for (int i = 1; i < n; i++)
	{
		vector<LL> foo;
		for (int col = i, row = n - 1; col < n; col++, row--)
			foo.push_back(v[row][col]);
		ans = max(ans, kadane(foo));
	}
	cout << ans;
	return 0;
}
