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
	int n, K, ans = INT_MIN;
	cin >> n >> K;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			multiset<int> a, b;
			int sum = 0;
			for (int k = 0; k < i; k++)
				a.insert(v[k]);
			for (int k = i; k <= j; k++)
				b.insert(v[k]), sum += v[k];
			for (int k = j + 1; k < n; k++)
				a.insert(v[k]);
			for (int k = 0; k < K and not a.empty() and not b.empty(); k++)
			{
				int A = *(a.rbegin());
				int B = *(b.begin());
				if (A <= B)
					break;
				sum += A - B;
				a.erase(a.find(A));
				b.erase(b.find(B));
			}
			ans = max(ans, sum);
		}
	cout << ans << endl;
	return 0;
}
