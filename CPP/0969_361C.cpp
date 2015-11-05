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

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=1; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

pair<pair<int, int>, pair<int, int> > v[5050];

int main()
{
	int n, m;
	SI(n); SI(m);
	vector<int> a(n+1, 0), empty(n+1, 1);
	for(int i=0; i<m; i++)
	{
		SI(v[i].f.f); SI(v[i].f.s);
		SI(v[i].s.f); SI(v[i].s.s);
	}
	for(int i=m-1; i>=0; i--)
	{
		if(v[i].f.f == 1)
		{
			for(int j=v[i].f.s; j<=v[i].s.f; j++)
				if(!empty[j])
					a[j] -= v[i].s.s;
		}
		else
			for(int j=v[i].f.s; j<=v[i].s.f; j++)
			{
				if(empty[j])
				{
					empty[j] = 0;
					a[j] = v[i].s.s;
				}
				else
					a[j] = min(a[j], v[i].s.s);
			}
	}
	vector<int> b(a);
	int i;
	for(i=0; i<m; i++)
		if(v[i].f.f == 1)
			for(int j=v[i].f.s; j<=v[i].s.f; j++)
				a[j] += v[i].s.s;
		else
		{
			int mx = INT_MIN;
			for(int j=v[i].f.s; j<=v[i].s.f; j++)
				mx = max(mx, a[j]);
			if(mx != v[i].s.s)
				break;
		}
	if(i==m)
	{
		printf("YES\n");
		print_array_v(b);
	}
	else
		printf("NO\n");
	return 0;
}
