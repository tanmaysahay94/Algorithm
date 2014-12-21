
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
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

ULL calc(vector<string> &a, vector< VULL > &tot, int i, int j)
{
	if(tot[i][j]!=-1)
		return tot[i][j];
	int n = a.size();
	if(i==n-1 && j==n-1)
		return tot[i][j] = 1;
	tot[i][j] = 0;
	if(a[i][j] == '#')
		return tot[i][j];
	if(i<n-1)
		tot[i][j] += calc(a, tot, i+1, j);
	if(j<n-1)
		tot[i][j] += calc(a, tot, i, j+1);
	return tot[i][j];
}

void calcTo(vector<string> &a, vector< VULL > &to)
{
	int n = a.size();
	to[0][0] = 1;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if(i==0 && j==0)
				continue;
			if(a[i][j] == '#')
				continue;
			if(i>0)
				to[i][j] += to[i-1][j];
			if(j>0)
				to[i][j] += to[i][j-1];
		}
}

void print2d(vector< VULL > v)
{
	EACH(it, v)
		print_array_v(*it);
	cout<<endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		vector<string> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		vector< VULL > from(n, VULL(n, -1)), to(n, VULL(n, 0));
		from[0][0] = calc(a, from, 0, 0);
		calcTo(a, to);
		ULL mx = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				if((i==0 && j==0) || (i==n-1&&j==n-1))
					continue;
				mx = max(mx, from[i][j]*to[i][j]);
			}
		printf("%llu\n", from[0][0] - mx);
	}
	return 0;
}
