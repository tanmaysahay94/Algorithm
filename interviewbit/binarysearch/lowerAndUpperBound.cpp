#include <bits/stdc++.h>

using namespace std;

int getLowerBound(vector<int> v, int search)
{
	int beg = 0, end = v.size() - 1;
	while (beg < end)
	{
		int mid = (beg + end) / 2;
		if (A[mid] < search)
			beg = mid + 1;
		else
			end = mid;
	}
	return beg;
}

int getUpperBound(vector<int> v, int search)
{
	int beg = 0, end = v.size() - 1;
	while (beg < end)
	{
		int mid = (beg + end) / 2;
		if (A[mid] <= search)
			beg = mid + 1;
		else
			end = mid;
	}
	return beg;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int search;
	cin >> search;
	int lower_bnd = getLowerBound(v, search);
	int upper_bnd = getUpperBound(v, search);
	printf("[%d %d]\n", lower_bnd, upper_bnd);
	return 0;
}
