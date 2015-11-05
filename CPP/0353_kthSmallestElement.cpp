#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <vector>

using namespace std;

int partition(vector<int>& list, int left, int right, int pivotIndex)
{
	int i, pivotValue = list[pivotIndex];
	swap(list[pivotIndex], list[right]);
	int storeIndex = left;						//storeIndex points to the first number in the set that's greater than pivotValue
	for (i = left; i <= right - 1; i++)
		if (list[i] < pivotValue)
			swap(list[storeIndex++], list[i]);
	swap(list[right], list[storeIndex]);
	return storeIndex;
}

int select(vector<int>& list, int left, int right, int n)
{
	if (left == right)
		return list[left];
	int pivotIndex = rand() % (right - left + 1) + left;
	pivotIndex = partition(list, left, right, pivotIndex);
	if (n == pivotIndex)
		return list[n];
	if (n < pivotIndex)
		return select(list, left, pivotIndex - 1, n);
	return select(list, pivotIndex + 1, right, n);
}

int main()
{
	srand(time(0));
	int n, kth, i;
	cin >> n;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	cin >> kth;
	assert (kth > 0 and kth <= n);
	cout << select(v, 0, v.size() - 1, kth - 1) << endl;
	return 0;
}
