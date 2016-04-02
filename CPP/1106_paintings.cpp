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
	int A[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);
	int ans = 0, i = 0, j = 0;
	while (i < n and j < n)
	{
		while (j < n and A[i] == A[j]) j++;
		if (i < n and j < n and A[i] < A[j]) ans++;
		i++, j++;
	}
	printf("%d\n", ans);
	return 0;
}
