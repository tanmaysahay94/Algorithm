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

typedef long long LL;

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n), loc(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
			loc[--v[i]] = i;
		}
		bool possible = true;
		for (int i = 0; i < n and possible; i++)
			if (i - loc[i] > 2)
				possible = false;
		if (not possible)
		{
			printf("Too chaotic\n");
			continue;
		}
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int num = i;
			while (num != v[num])
			{
				int idx = loc[num];
				swap(v[idx], v[idx + 1]);
				loc[num] = idx + 1;
				loc[v[idx]] = idx;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
