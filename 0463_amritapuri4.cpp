#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i].f<<" "<<a[i].s<<"  ";
	cout<<endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int> > v(n, vector<int> (m));
		vector<vector<pair<LL, LL> > > presum(n+1, vector<pair<LL, LL> > (m+2, mp(0, 0)));
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &v[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				presum[i][j].f = presum[i-1][j-1].f + v[i-1][j-1];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				presum[i][j].s = presum[i-1][j+1].s + v[i-1][j-1];
//		for(int i=0; i<n; i++)
//			print_array_v(presum[i]);
		int mn = min(m, n);
		LL mx = INT_MIN;
		for(int size = 2; size <= mn; size++)
		{
			for(int i=size; i<=n; i++)
				for(int j=size; j<=m; j++)
				{
					LL sum = presum[i][j].f - presum[i-size][j-size].f;
					sum += presum[i][j+1-size].s - presum[i-size][j+1].s;
					if(size&1)
						sum -= v[i-1 - size/2][j-1 - size/2];
					mx = max(mx, sum);
				}
		}
		printf("%lld\n", mx);
	}
	return 0;
}

