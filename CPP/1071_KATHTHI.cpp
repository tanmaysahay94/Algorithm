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

const int maxr = 1005;
const int inf = maxr<<1;
char grid[maxr][maxr];//
vector<vector<int> > ans(maxr, vector<int> (maxr, inf));
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int R, C;//

inline bool isValid(int i, int j)
{
	return (0 <= i) && (i < R) && (0 <= j) && (j < C);
}

inline char at(int i, int j)
{
	return grid[i][j];
}

int main()
{
	int __T;
	scanf("%d", &__T);//
	for (int t = 1; t <= __T; t++)//
	{
		scanf("%d%d", &R, &C);//
		for (int i = 0; i < R; i++)//
			for (int j = 0; j < C; j++)//
				ans[i][j] = inf;//
		for (int i = 0; i < R; i++)//
			scanf("%s", grid[i]);//
		deque<pair<int, int> > D;//
		D.push_back(make_pair(0, 0));//
		ans[0][0] = 0;//
		while (D.size())// //and not (D.front().first == R - 1 and D.front().second == C - 1))
		{
			pair<int, int> front = D.front(); D.pop_front();//
			int i = front.first, j = front.second;//
			if (i == R - 1 and j == C - 1) break;//
			for (int k = 0; k < 4; k++)//
			{
				int ni = i + di[k];//
				int nj = j + dj[k];//
				if (!isValid(ni, nj)) continue;//
				if (at(i, j) == at(ni, nj))
				{
					if (ans[i][j] < ans[ni][nj])
						ans[ni][nj] = ans[i][j], D.push_front(make_pair(ni, nj));
				}
				else
				{
					if (ans[i][j] + 1 < ans[ni][nj])
						ans[ni][nj] = ans[i][j] + 1, D.push_back(make_pair(ni, nj));
				}
			}
		}
		printf("%d\n", ans[R - 1][C - 1]);//
	}
	return 0;
}
