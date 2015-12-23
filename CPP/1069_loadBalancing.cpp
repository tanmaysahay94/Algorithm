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
	LL n;
	scanf("%lld", &n);
	vector<LL> v(n);
	LL sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &v[i]);
		sum += v[i];
	}
	LL avg = sum / n;
	LL rem = sum % n;
	sort(v.begin(), v.end());
	int i;
	LL time = 0;
	for (i = 0; i < n - rem; i++)
		time += abs(v[i] - avg);
	avg++;
	for (; i < n; i++)
		time += abs(v[i] - avg);
	time >>= 1;
	printf("%lld\n", time);
	/*
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
	}
	*/
	return 0;
}
