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
	int neg = 0, pos = 0;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	for (int i = 0; i < n; i++)
	{
		int cross = (v[(i+1)%n].first-v[i%n].first)*(v[(i+2)%n].second-v[(i+1)%n].second) - (v[(i+2)%n].first-v[(i+1)%n].first)*(v[(i+1)%n].second-v[i%n].second);
		if (cross < 0) neg++;
		else if (cross > 0) pos++;
	}
	printf("%d\n", min(pos, neg));
	return 0;
}
