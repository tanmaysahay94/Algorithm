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

int main()
{
	int n;
	scanf("%d", &n);
	int s;
	scanf("%d", &s);
	int ans = 0;
	bool skip = false;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		if (val <= s) ans++;
		else
		{
			if (!skip) skip = true;
			else break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
