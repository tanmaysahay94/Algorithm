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

typedef long long LL;

const LL mod = 1LL << 32;
const LL sze = mod >> 6;

long long H[sze];

int main()
{
	int __T;
	scanf("%d", &__T);
	LL sum = 0;
	LL S, A, B, F;
	int cll, bit;
	scanf("%lld%lld%lld", &S, &A, &B);
	for (int t = 1; t <= __T; t++)
	{
		if (t != 1) S = ((A * S) % mod + B) % mod;
		F = S >> 1;
		cll = F >> 6, bit = F % 64;
		if (S&1 && (!((H[cll] >> bit) & 1LL))) sum += F, H[cll] |= (1LL << bit);
		else if ((H[cll] >> bit) & 1LL) sum -= F, H[cll] &= (~(0) | (1LL << bit));
	}
	printf("%lld\n", sum);
	return 0;
}
