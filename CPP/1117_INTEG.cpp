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
	int N;
	LL X;
	scanf("%d", &N);
	vector<LL> v;
	for (int i = 0; i < N; i++)
	{
		LL val;
		scanf("%lld", &val);
		if (val < 0) v.push_back(-val);
	}
	scanf("%lld", &X);
	LL cost = 0;
	N = v.size();
	if (not X or not N)
		printf("0\n");
	else
	{
		sort(v.begin(), v.end());
		LL diff = 0, mini, cnt;
		for (int i = 0; i < N; )
		{
			mini = v[i] - diff;
			cnt = N - i;
			if (cnt >= X)
				cost += mini * X;
			else
				cost += mini * cnt;
			diff += mini;
			while (i < N and v[i] - diff == 0)
				i++;
		}
		printf("%lld\n", cost);
	}
	return 0;
}
