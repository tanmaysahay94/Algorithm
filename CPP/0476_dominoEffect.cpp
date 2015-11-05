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

int main()
{
	int n;
	scanf("%d", &n);
	int count = 0, prind = -1;
	char a[3030], prev = 'L';
	scanf("%s", a);
	a[n] = 'R';
	a[n+1] = 0;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == 'R')
		{
			if(prev == 'L')
				count += i - prind - 1;
			prev = 'R';
			prind = i;
		}
		else if(a[i]=='L')
		{
			if(prev == 'R' && ((i-prind)%2 == 0))
				count++;
			prev = 'L';
			prind = i;
		}
//		printf("prev: %c  prind: %d  count: %d\n", prev, prind, count);
	}
	printf("%d\n", count);
	return 0;
}
