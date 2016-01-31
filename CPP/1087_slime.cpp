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
	int __T;
	scanf("%d", &__T);
	stack<LL> S;
	for (int t = 1; t <= __T; t++)
	{
		LL up = 1;
		while (S.size() and S.top() == up)
		{
			up++;
			S.pop();
		}
		S.push(up);
	}
	vector<LL> v;
	while (S.size())
	{
		v.push_back(S.top());
		S.pop();
	}
	reverse(v.begin(), v.end());
	for (auto &vv: v)
		printf("%lld ", vv);
	printf("\n");
	return 0;
}
