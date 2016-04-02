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

LL divide(LL a, LL b)
{
	LL ret = 0;
	while (a >= b)
	{
		int cnt = 0;
		while (b << 1 <= a) b <<= 1, cnt++;
		a -= b;
		ret |= (1LL << cnt);
	}
	return ret;
}

int main()
{
	LL a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", divide(a, b));
	/*
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
	}
	*/
	return 0;
}
