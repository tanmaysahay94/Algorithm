#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;
long long T[maxn][maxn][maxn];

void init()
{
	for (int x = 1; x < maxn; x++)
		for (int y = 1; y < maxn; y++)
			for (int z = 1; z < maxn; z++)
			{
				T[x][y][z] += T[x - 1][y - 1][z - 1];
				T[x][y][z] -= T[x][y - 1][z - 1];
				T[x][y][z] -= T[x - 1][y][z - 1];
				T[x][y][z] -= T[x - 1][y - 1][z];
				T[x][y][z] += T[x - 1][y][z];
				T[x][y][z] += T[x][y - 1][z];
				T[x][y][z] += T[x][y][z - 1];
			}
}

long long query(int xx, int yy, int zz)
{
	return T[xx][yy][zz];
}

inline void U(int& foo)
{
	foo += 102;
}

int main()
{
	memset(T, 0, sizeof(T));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		U(x), U(y), U(z);
		T[x][y][z]++;
	}
	init();
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x1, y1, z1, x2, y2, z2;
		scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);

		U(x1), U(y1), U(z1), U(x2), U(y2), U(z2);

		long long ans = query(x2, y2, z2);

		ans -= query(x1, y2, z2);
		ans -= query(x2, y1, z2);
		ans -= query(x2, y2, z1);

		ans += query(x2, y1, z1);
		ans += query(x1, y2, z1);
		ans += query(x1, y1, z2);

		ans -= query(x1, y1, z1);
		printf("%lld\n", ans);
	}
	return 0;
}
