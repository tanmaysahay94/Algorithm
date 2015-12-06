#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("alarm.in");
	ofstream fout("alarm.out");
	int n;
	fin >> n;
	int lim = 10;
	vector<int> v(10);
	v[0] = 6;
	v[1] = 2;
	v[2] = 5;
	v[3] = 5;
	v[4] = 4;
	v[5] = 5;
	v[6] = 6;
	v[7] = 3;
	v[8] = 7;
	v[9] = 6;
	vector<int> ans(4);
	bool found = false;
	for (int i = 0; i < lim and not found; i++)
		for (int j = 0; j < lim and not found; j++)
			for (int k = 0; k < lim and not found; k++)
				for (int l = 0; l < lim and not found; l++)
				{
					if (10 * i + j >= 24 or 10 * k + l >= 60) continue;
					if (v[i] + v[j] + v[k] + v[l] == n)
					{
						found = true;
						ans[0] = i;
						ans[1] = j;
						ans[2] = k;
						ans[3] = l;
					}
				}
	if (not found)
		fout << "Impossible" << endl;
	else
		fout << ans[0] << ans[1] << ":" << ans[2] << ans[3] << endl;
	return 0;
}
