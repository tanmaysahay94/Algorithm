#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
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
	vector<int> dp(n, 0);		// dp[i] array stores max donation upto i-th person
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0] = v[0];				// case 1 - when first guy is present -> last guy is not present. so, answer is stored in dp[n-2]
	for (int i = 2; i < n - 1; ++i)
		dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
	int val1 = dp[n - 2];
	for (int i = 0; i < n; ++i)
		dp[i] = 0;
	dp[1] = v[1];				// case 2 - when second guy is present -> first guy is absent. so, answer is stored in dp[n-1]
	for (int i = 2; i < n; ++i)
		dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
	int val2 = dp[n - 1];
	cout << max(val1, val2) << endl;
}
