#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <string.h>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n);		//dp[i] denotes largest contiguous sum where i is the last term to be added
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = dp[0] = v[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
