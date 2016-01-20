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
const LL inf = LLONG_MAX;

int main()
{
	LL l, r, k;
	cin >> l >> r >> k;
	LL v = 1, cnt = 0;
	while (v < l and inf / v >= k) v *= k;
	while (v <= r and inf/ v >= k)
	{
		cnt++;
		cout << v << ' ';
		v *= k;
	}
	if (l <= v and v <= r and v > 0)
	{
		cnt++;
		cout << v << ' ';
	}
	if (!cnt) cout << -1; cout << endl;
	return 0;
}
