#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& v, int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void partition(vector<int>& v, int k, int n)
{
	int i, lesser = 0;
	swap(v, 0, k);
	for (i = 1; i < n; i++)
		if (v[i] < v[0])
			swap(v, i, ++lesser);
	swap(v, 0, lesser);
}

int main()
{
	int n, i, k;
	cout << "Size of array: ";
	cin >> n;
	vector<int> v(n);
	cout << "Input " << n << " elements.\n";
	for (i = 0; i < n; i++)
		cin >> v[i];
	cout << "Index around which partition is required (i < n, 0-index): ";
	cin >> k;
	partition(v, k, n);
	for (i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}
