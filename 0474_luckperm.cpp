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

int arr[100100];

void shuff(int a, int b, int c, int d)
{
	arr[a] = b;
	arr[b] = d;
	arr[c] = a;
	arr[d] = c;
}

int main()
{
	LL n;
	cin >> n;
	int rem = n%4;
	if(rem<2)
	{
		for(int i=1; i<n/2; i+=2)
			shuff(i, i+1, n-i, n-i+1);
		if(rem == 1)
			arr[n/2 + 1] = n/2 + 1;
		for(int i=1; i<=n; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("-1");
	printf("\n");
	return 0;
}
