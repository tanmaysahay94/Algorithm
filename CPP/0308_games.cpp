#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int t, i, j, count = 0;
	cin >> t;
	vector< pair<int, int> > v(t);
	for (i = 0; i < t; i++)
		cin >> v[i].first >> v[i].second;
	for (i = 0; i < t; i++)
		for (j = 0; j < t; j++)
			if (i != j)
				if (v[i].first == v[j].second)
					count++;
	cout << count << endl;
}
