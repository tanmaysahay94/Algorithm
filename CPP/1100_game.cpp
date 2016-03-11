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

const int maxn = 2005;
const int maxa = 5005;

int n;
LL A[maxn];
vector<LL> pre;
unordered_map<LL, LL> P, Q;

int main()
{
	scanf("%d", &n);
	double denom = (n * (n + 1)) / 2;
	denom *= denom * denom;
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	sort(A, A + n);
	LL threshold = A[n - 1] - A[0];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] - A[i] >= threshold)
				break;
			P[A[j] - A[i]]++;
		}
	int maxd = 0;
	for (auto p = P.begin(); p != P.end(); p++)
		for (auto q = p; q != P.end(); q++)
		{
			if (p -> first + q -> first >= threshold)
				break;
			Q[p -> first + q -> first] += p -> second * q -> second;
		}
	pre = vector<LL> (maxd + 1, 0);
	for (auto &q: Q)
		pre[q.first] = q.second;
	return 0;
}
