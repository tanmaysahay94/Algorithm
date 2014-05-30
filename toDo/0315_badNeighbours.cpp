#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int maxDonations(vector<int>& v)
{
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << maxDonations(v);
}
