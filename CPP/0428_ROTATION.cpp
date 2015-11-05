#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL my_mod(LL val, LL modulus)
{
	int ret = val % modulus;
	if (ret < 0)
		ret += modulus;
	return ret;
}

int main()
{
	LL n, m, i, arg, offset = 0;
	char op;
	SLL(n); SLL(m);
	VLL v(n);
	for (i = 0; i < n; i++)
		SLL(v[i]);
	getchar();
	while (m--)
	{
		scanf("%c%lld", &op, &arg);
		getchar();
		if (op == 'C')
			offset = my_mod(offset + arg, n);
		else if (op == 'A')
			offset = my_mod(offset - arg, n);
		else
			printf("%lld\n", v[my_mod(offset + arg - 1, n)]);
	}
	return 0;
}
