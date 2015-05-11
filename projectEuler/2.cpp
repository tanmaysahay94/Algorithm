#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<long long> v;

int main()
{
	optimizeIO();
	v.push_back(1);
	v.push_back(1);
	long long sum = 2;
	int idx = 1;
	while (sum <= 4e16)
	{
		v.push_back(sum);
		idx++;
		sum = v[idx - 1] + v[idx];
	}
	vector<long long> presum(v.size());
	presum[0] = 0;
	for (int i = 1; i < (int) v.size(); i++)
	{
		presum[i] = presum[i - 1];
		if (v[i] % 2 == 0)
			presum[i] += v[i];
	}
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		vector<long long>::iterator it;
		it = lower_bound(v.begin(), v.end(), n);
		idx = it - v.begin();
		cout << presum[idx-1] << endl;
	}
	return 0;
}
