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

unordered_map<int, int> mp;

int minSumPow(int n, int p)
{
	if (mp.count(n)) return mp[n];
	if (n == 0)
		return 0;
	int x = __root(n, p);
	int ans = INT_MAX;
	for (int i = 1; i <= x; i++)
		ans = min(ans, minSumPow(n - __pow(i, p), p) + 1);
	return mp[n] = ans;
}

int main()
{
	/*
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
	}
	*/
	return 0;
}
