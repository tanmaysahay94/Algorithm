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

const int maxn = 505;
int A[maxn][maxn];

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &A[i][j]);
		for (int col = 0; col < M; col++)
		{
			int col_ = col;
			int row_ = 0;
			while (col_ >= 0 and row_ < N) printf("%d ", A[row_++][col_--]);
		}
		for (int row = 1; row < N; row++)
		{
			int col_ = M - 1;
			int row_ = row;
			while (col_ >= 0 and row_ < N) printf("%d ", A[row_++][col_--]);
		}
		printf("\n");
	}
	return 0;
}
