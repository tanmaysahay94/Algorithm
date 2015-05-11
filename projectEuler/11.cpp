#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long v[20][20];

int main()
{
	optimizeIO();
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			cin >> v[i][j];
	int ans = -1;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j <= 16; j++)
		{
			int tmp = 1;
			for (int k = j; k < j + 4; k++)
				tmp *= v[i][k];
			ans = max(ans, tmp);
		}
	for (int i = 0; i < 20; i++)
		for (int j = 0; j <= 16; j++)
		{
			int tmp = 1;
			for (int k = j; k < j + 4; k++)
				tmp *= v[k][i];
			ans = max(ans, tmp);
		}
	for (int i = 0; i <= 16; i++)
		for (int j = 0; j <= 16; j++)
			ans = max((long long)ans, v[i][j]*v[i+1][j+1]*v[i+2][j+2]*v[i+3][j+3]);
	for (int i = 3; i < 20; i++)
		for (int j = 0; j <= 16; j++)
			ans = max((long long)ans, v[i][j]*v[i-1][j+1]*v[i-2][j+2]*v[i-3][j+3]);
	cout << ans << endl;
	return 0;
}
