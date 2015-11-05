#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

long long heap[100005];
int main() 
{
	long long n, i, test;
	cin >> test;
	while (test--) 
	{
		bool t = false;
		cin >> n;
		vector<long long> arr(100005);
		for (i = 1; i <= n; i++)
		{
			cin >> arr[i];
			heap[i] = heap[i - 1] + arr[i];
		}
		for (i = 2; i < n; i++)
			if (heap[i - 1] == heap[n] - heap[i])
				t = true;
		if (t || n == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
