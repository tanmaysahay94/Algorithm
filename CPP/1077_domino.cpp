#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

const int maxn = 555;

char S[maxn][maxn];
int hor[maxn][maxn], ver[maxn][maxn];

int main()
{
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", S[i]);
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++)
		{
			if (i == 0 or j == 0)
				hor[i][j] = 0, ver[i][j] = 0;
			else
			{
				hor[i][j] = hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
				if (j < w and S[i - 1][j - 1] == '.' and S[i - 1][j] == '.')
					hor[i][j]++;
				ver[i][j] = ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
				if (i < h and S[i - 1][j - 1] == '.' and S[i][j - 1] == '.')
					ver[i][j]++;
			}
		}
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int r1, c1, r2, c2;
		int ans = 0;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		ans += ver[r2 - 1][c2] - ver[r2 - 1][c1 - 1] - ver[r1 - 1][c2] + ver[r1 - 1][c1 - 1];
		ans += hor[r2][c2 - 1] - hor[r1 - 1][c2 - 1] - hor[r2][c1 - 1] + hor[r1 - 1][c1 - 1];
		printf("%d\n", ans);
	}
	return 0;
}
