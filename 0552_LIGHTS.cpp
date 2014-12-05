#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, k;
		SI(n); SI(m); SI(k);
		char a[60][60];
		priority_queue<int> q;
		for(int i=0; i<n; i++)
		{
			scanf("%s", a[i]);
			int cnt = 0;
			for(int j=0; j<m; j++)
				if(a[i][j] == '*')
					cnt++;
			q.push(-cnt);
		}
		for(int i=0; i<k; i++)
		{
			int ele = m+q.top();
			q.pop();
			q.push(-ele);
		}
		int tot = 0;
		while(!q.empty())
		{
			tot -= q.top();
			q.pop();
		}
		printf("%d\n", tot);
	}
	return 0;
}
