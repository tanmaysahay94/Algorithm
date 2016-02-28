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

int findNext(int a, int b)
{
	a++;
	while (a % b) a++;
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (n or m)
	{
		if (n == 0)
		{
			ans = findNext(ans, 3);
			ans += 3 * (m  - 1);
			break;
		}
		if (m == 0)
		{
			ans = findNext(ans, 2);
			ans += 2 * (n  - 1);
			break;
		}
		ans++;
		if (ans % 2 + ans % 3 == 0)
		{
			if (n > m) n--;
			else m--;
		}
		else if (ans % 2 == 0) n--;
		else if (ans % 3 == 0) m--;
	}
	cout << ans << endl;
	return 0;
}
