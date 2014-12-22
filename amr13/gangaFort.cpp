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
		cout<<a[i].f<<" "<<a[i].s<<endl;
	cout<<endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL cost = 0, mncost = INT_MAX;
		vector< pair<LL, LL> > v1, v2;
		vector< pair<LL, LL> >::iterator end, start;
		LL n, m, k;
		SLL(n); SLL(m); SLL(k);
		LL a, b, x;
		for(int i=0; i<m; i++)
		{
			SLL(a); SLL(b); SLL(x);
			v1.pb(mp(a, x));
			v2.pb(mp(b, x));
		}
		v1.pb(mp(0, 0));
		v2.pb(mp(0, 0));
		v1.pb(mp(n+1, 0));
		v2.pb(mp(n+1, 0));
		sortv(v1);
		sortv(v2);
//		print_array_v(v1);
//		print_array_v(v2);
		start = v2.begin();
		end = v1.begin();
		for(int i=0; i<2*m+4; i++)
		{
			if(end->f - (start->f+1) < k)
			{
				if(end != v1.end()-1)
				{
					cost += end->s;
					end++;
				}
			}
			else
			{
				mncost = min(mncost, cost);
				if(start != v2.end()-1)
				{
					start++;
					cost -= start->s;
				}
			}
//			printf("%lld %lld %lld\n", cost, start->f, end->f);
		}
		printf("%lld\n", mncost);
	}
	return 0;
}

