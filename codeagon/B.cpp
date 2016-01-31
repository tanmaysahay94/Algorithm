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
const int maxa = 1e6 + 5;

vector<int> sieve(maxa);
vector<LL> splVal(maxa);

void init()
{
	sieve = vector<int> (maxa, 1);
	splVal = vector<LL> (maxa, 0);
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i < maxa; i++)
		if (sieve[i])
		{
			splVal[i]++;
			for (int j = 2 * i; j < maxa; j += i)
			{
				sieve[j] = 0;
				int k = j;
				while (k % i == 0 and k != 1)
				{
					k /= i;
					splVal[j]++;
				}
			}
		}
	for (int i = 2; i < maxa; i++)
		splVal[i] += splVal[i - 1];
}

int main()
{
	init();
	int n;
	scanf("%d", &n);
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	long long ans(0);
	int mask = 1 << n;
	for (int i = 1; i < mask; i++)
	{
		LL sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += splVal[A[j]];
		if (sum % 2 == 0) ans += sum;
	}
	printf("%lld\n", ans);
	return 0;
}
