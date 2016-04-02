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

bool isSame(int h, int dig)
{
	if (h == 0 and dig)
		return false;
	while (h)
	{
		if (h % 10 != dig)
			return false;
		h /= 10;
	}
	return true;
}

int f(int h, int m)
{
	if (not isSame(h, h % 10))
		return 0;
	int ret = 0;
	for (int minute = 0; minute < m; minute++)
		if (isSame(minute, h % 10))
			ret++;
	return ret;
}

int solve(int h, int m)
{
	int ret = 0;
	for (int hour = 0; hour < h; hour++)
		ret += f(hour, m);
	return ret;
}

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int h, m;
		scanf("%d%d", &h, &m);
		printf("%d\n", solve(h, m));
	}
	return 0;
}
