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

const int maxn = 1e5 + 5;
int A[maxn];

int main()
{
	int N, Q;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A, A + N);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int foo = lower_bound(A, A + N, a) - A;
		int bar = upper_bound(A, A + N, b) - A;
		printf("%d\n", bar - foo);
	}
	return 0;
}
