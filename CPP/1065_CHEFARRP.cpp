#include <bits/stdc++.h>

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

using namespace std;

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int n;
		scanf("%d", &n);
		vector<int> psum, ppro;
		psum.push_back(0);
		ppro.push_back(1);
		for (int i = 0; i < n; i++)
		{
			int val;
			scanf("%d", &val);
			psum.push_back(psum[psum.size() - 1] + val);
			ppro.push_back(ppro[ppro.size() - 1] * val);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				if (psum[j] - psum[i - 1] == ppro[j] / ppro[i - 1])
					cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
