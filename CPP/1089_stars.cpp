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

vector<pair<pair<LL, LL>, int> > S;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		S.push_back(make_pair(make_pair(x, y), i));
	}
	sort(S.begin(), S.end());
	for (int i = 0; i < 2; i++) printf("%d ", S[i].second);
	int i = 2;
	while (i < (int) S.size())
	{
		LL area = 0;
		area += S[0].first.first * S[1].first.second;
		area += S[1].first.first * S[i].first.second;
		area += S[i].first.first * S[0].first.second;
		area -= S[0].first.first * S[i].first.second;
		area -= S[i].first.first * S[1].first.second;
		area -= S[1].first.first * S[0].first.second;
		if (area == 0) i++;
		else
		{
			printf("%d\n", S[i].second);
			break;
		}
	}
	return 0;
}
