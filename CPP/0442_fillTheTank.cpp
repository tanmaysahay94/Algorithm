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

bool po[1000000001] = {0};

int main()
{
	int B, Q;
	scanf("%d%d", &B, &Q);
	vector<int> b(B);
	int q[100100];
	for(int i=0; i<B; i++)
	{
		scanf("%d", &b[i]);
		po[b[i]] = 1;
	}
	int m = 0;
	for(int i=0; i<Q; i++)
	{
		scanf("%d", q+i);
		m = max(m, q[i]);
	}
	for(int i=0; i<b.size(); i++)
	{
		int changes = 0;
		for(int j=i; j<b.size(); j++)
			if(!po[b[i]+b[j]] && (b[i]+b[j])<=m)
			{
				b.pb(b[i]+b[j]);
				po[b[i]+b[j]] = 1;
				changes = 1;
			}
		if(changes)
			i = -1;
	}
/*	for(int i=0; i<b.size(); i++)
		cout<<b[i]<<" ";
	cout<<endl;
*/	for(int i=0; i<Q; i++)
		if(po[q[i]])
			printf("yes\n");
		else
			printf("no\n");
	return 0;
}
