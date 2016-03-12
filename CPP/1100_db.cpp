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

unordered_map<string, int> u_map;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		string s;
		cin >> s;
		if (u_map.count(s))
		{
			cout << s << u_map[s] << endl;
			u_map[s]++;
		}
		else
		{
			cout << "OK" << endl;
			u_map[s] = 1;
		}
	}
	return 0;
}
