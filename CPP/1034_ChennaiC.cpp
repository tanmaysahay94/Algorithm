
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n; SI(n);
		int a[110];
		for(int i=0; i<n; i++)
			SI(a[i]);
		a[n] = INT_MAX;
		multiset<int> ms[2][110];
		int ans[110][110];
		ans[0][n] = 0;
		for(int j=n-1; j>=0; j--)
		{
			int ind = j%2;
			int oth = !ind;
			for(int i=0; i+j<=n; i++)
			{
				ans[i][j] = INT_MAX;
				multiset<int>::iterator it;
				if(i+j < n)
				{
					int cnt, cnt2;
					for(cnt = 0, it = ms[oth][i].lower_bound(a[i+j]); it!=ms[oth][i].begin(); it--, cnt++); 
					for(cnt2 = 0, it = ms[oth][i].upper_bound(a[i+j]); it!=ms[oth][i].end(); it++, cnt2++);
					ans[i][j] = ans[i][j+1] + min(cnt, cnt2);
				}
				if(i>0)
				{
					int cnt, cnt2;
					for(cnt = 0, it = ms[oth][i-1].lower_bound(a[i-1]); it!=ms[oth][i-1].begin(); it--, cnt++); 
					for(cnt2 = 0, it = ms[oth][i-1].upper_bound(a[i-1]); it!=ms[oth][i-1].end(); it++, cnt2++);
					ans[i][j] = min(ans[i][j], ans[i-1][j+1] + min(cnt, cnt2));
				}
				if(i > 0)
				{
					ms[ind][i] = ms[oth][i-1];
					ms[ind][i].insert(a[i-1]);
				}
				else
				{
					ms[ind][i] = ms[oth][i];
					ms[ind][i].insert(a[i+j]);
				}
			}
		}
		int fa = INT_MAX;
		for(int i=0; i<=n; i++)
			fa = min(fa, ans[i][0]);
		cout<<fa<<endl;
	}
	return 0;
}
