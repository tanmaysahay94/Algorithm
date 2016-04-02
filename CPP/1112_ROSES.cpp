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

char str[10];

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int N;
		scanf("%d%s", &N, str);
		LL ans = 0;
		int ocnt = 0, smallest = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			int val;
			scanf("%d", &val);
			ans += val;
			if (val & 1)
				ocnt++, smallest = min(smallest, val);
		}
		if (str[0] == 'H')		// odd
		{
			if (ocnt == 0)
			{
				printf("Sad\n");
				continue;
			}
			if (ocnt % 2 == 0)
				ans -= smallest;
			printf("%lld\n", ans);
		}
		else					// even
		{
			if (ocnt & 1)
				ans -= smallest;
			if (ans == 0)
				printf("Sad\n");
			else
				printf("%lld\n", ans);
		}
	}
	return 0;
}
