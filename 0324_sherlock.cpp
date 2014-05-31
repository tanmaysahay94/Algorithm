#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

using namespace std;

int main() 
{
	bool t = false;
	long long n, i, test;
	cin >> test;
	while (test--) 
	{
		cin >> n;
		vector<long long> arr(n), left(n, 0), right(n, 0);
		for (i = 0; i < n; i++)
			cin >> arr[i];
		for (i = 1; i < n; i++)
			right[0] += arr[i];
		for (i = 1; i < n; i++)
			right[i] = right[i - 1] - arr[i];
		for (i = n - 2; i >= 0; i--)
			left[n - 1] += arr[i];
		for (i = n - 2; i >= 0; i--)
			left[i] = left[i + 1] - arr[i];
		for (i = 0; i < n; i++)
			if (right[i] == left[i]) 
			{
				t = true;
				break;
			}
		if (t) 
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}
