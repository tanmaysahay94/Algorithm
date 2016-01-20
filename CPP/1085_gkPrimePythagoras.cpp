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

const int maxn = 1e5;

vector<int> sieve(maxn + 1, 1);
vector<LL> prime;
set<vector<LL> > S;

void init()
{
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i <= maxn; i++)
		if (sieve[i])
		{
			prime.push_back((LL)i);
			for (int j = 2 * i; j <= maxn; j += i)
				sieve[j] = 0;
		}
}

int main()
{
	init();
	LL prod = 1;
	for (int i = 0; i < 9; i++) prod *= prime[i];
	trace(prod);
	for (int i = 0; i < (int) prime.size(); i++)
		for (int j = i + 1; j < (int) prime.size(); j++)
		{
			LL sum = prime[i] * prime[i] + prime[j] * prime[j];
			LL sq = sqrt(sum);
			if (sq * sq == sum)
			{
				vector<LL> foo = {prime[i], prime[j], sq};
				sort(foo.begin(), foo.end());
				S.insert(foo);
			}
		}
	for (int i = 0; i < (int) prime.size(); i++)
		for (int j = i + 1; j < (int) prime.size(); j++)
		{
			LL sum = prime[j] * prime[j] - prime[i] * prime[i];
			LL sq = sqrt(sum);
			if (sq * sq == sum)
			{
				vector<LL> foo = {prime[i], prime[j], sq};
				sort(foo.begin(), foo.end());
				S.insert(foo);
			}
		}
	for (auto &s: S)
	{
		for (auto &ss: s)
			printf("%lld ", ss);
		printf("\n");
	}
	return 0;
}
