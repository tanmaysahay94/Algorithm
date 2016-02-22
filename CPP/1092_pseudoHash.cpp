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

map<vector<int>, int> mp;

int main()
{
	int n;
	char S[55];
	vector<int> cnt(26, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", S);
		cnt = vector<int> (26, 0);
		for (int j = 0; S[j]; j++) cnt[S[j] - 'a']++;
		mp[cnt]++;
	}
	int ans = -1;
	for (auto &m: mp)
		ans = max(ans, m.second);
	printf("%d\n", ans);
	return 0;
}
