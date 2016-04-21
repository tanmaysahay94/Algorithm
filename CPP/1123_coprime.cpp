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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	vector<int> sol;
	int k = 0;
	sol.push_back(v[0]);
	for (int i = 1; i < n; i++)
	{
		int gcd = __gcd(v[i - 1], v[i]);
		if (gcd > 1)
		{
			sol.push_back(1);
			k++;
		}
		sol.push_back(v[i]);
	}
	printf("%d\n", k);
	for (auto a: sol)
		printf("%d ", a);
	printf("\n");
	return 0;
}
