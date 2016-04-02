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

const int maxn = 1e5 + 5;
int ans[maxn], A[maxn];

inline int sign(int n)
{
	return n / (int (abs(n)));
}

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		ans[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
			if (sign(A[i]) * sign(A[i + 1]) == -1)
				ans[i] = ans[i + 1] + 1;
			else
				ans[i] = 1;
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
