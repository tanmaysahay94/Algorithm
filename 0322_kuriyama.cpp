#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main()
{
	long long int n, i, m, type, l, r;
	cin >> n;
	vector<long long int> stone(n);
	vector<long long int> heapsum(n + 1);
	vector<long long int> sortedstone(n);
	vector<long long int> heapsumsorted(n + 1);
	for (i = 0; i < n; i++)
	{
		cin >> stone[i];
		sortedstone[i] = stone[i];
	}
	sort(sortedstone.begin(), sortedstone.end());
	heapsum[0] = 0;
	heapsum[1] = stone[0];
	heapsumsorted[0] = 0;
	heapsumsorted[1] = sortedstone[0];
	for (i = 1; i < n; i++)
	{
		heapsum[i + 1] = heapsum[i] + stone[i];
		heapsumsorted[i + 1] = heapsumsorted[i] + sortedstone[i];
	}
	cin >> m;
	while (m--)
	{
		cin >> type >> r >> l;
		if (type == 1)
			cout << heapsum[l] - heapsum[r - 1] << endl;
		else
			cout << heapsumsorted[l] - heapsumsorted[r - 1] << endl;
	}
}
