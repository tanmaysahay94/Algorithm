#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<int> getOrdering(vector<int>& h, vector<int>& b, vector<int>& w)
{
	int n = h.size();
	vector<bool> placed(n, false);
	vector<int> result(n);
	for (int i = 0; i < n; ++i)
	{
		int best = -1;
		for (int j = 0; j < n; j++)
			if (!placed[j])
			{
				bool toSwitch = true;
				for (int k = 0; k < n; k++)
					if (k != j && !placed[k] && h[k] < h[j] && b[k] <= w[j] && w[k] >= b[j])
						toSwitch = false;
				if (toSwitch && (best == -1 || h[j] > h[best]))
					best = j;
			}
		result[i] = height[best];
		placed[best] = true;
	}
	return result;
}
int main()
{
	int n;
	cin >> n;
	vector<int> height(n), bloom(n), wilt(n);
	for (int i = 0; i < n; i++)
		cin >> height[i] >> bloom[i] >> wilt[i];
	vector<int> out = getOrdering(height, bloom, wilt);
	for (int i = 0; i < n; i++)
		cout << out[i] << endl;
}
