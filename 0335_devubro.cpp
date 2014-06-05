#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void show(vector<long long>& v)
{
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int main()
{
	long long n, m, i, target, total = 0;
	cin >> n >> m;
	vector<long long> devu(n), bro(m);
	for (i = 0; i < n; i++)
		cin >> devu[i];
	for (i - 0; i < m; i++)
		cin >> bro[i];
	sort(devu.begin(), devu.end());
	sort(bro.begin(), bro.end());
	while (devu[0] < bro[n - 1])
	{
		show(devu);
		show(bro);
		target = (devu[0] + bro[n - 1]) >> 1;
		total += bro[n - 1] - devu[0];
		printf("target: %d total %d\n", target, total);
		devu[0] = bro[n - 1] = target;
		i = 0;
		while (i < n - 1 && devu[i] > devu[i + 1])
			swap(devu[i], devu[i + 1]);
		i = m - 1;
		while (i && bro[i] < bro[i - 1])
			swap(bro[i], bro[i - 1]);
		show(devu);
		show(bro);
	}
	cout << total << endl;
}
