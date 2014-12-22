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
		cout<<a[i]<<" ";
	cout<<endl;
}

LL count_swaps(int a[], int b[], int n)
{
	vector< vector<LL> > swp(n, vector<LL>(2));
	swp[0][0] = 0;
	swp[0][1] = 1;
	for(int i=1; i<n; i++)
	{
		swp[i][0] = INT_MAX;
		swp[i][1] = INT_MAX;
		if(a[i] > a[i-1] && b[i] > b[i-1])
		{
			swp[i][0] = min(swp[i][0], swp[i-1][0]);
			swp[i][1] = min(swp[i][1], swp[i-1][1] + 1);
		}
		if(a[i] > b[i-1] && b[i] > a[i-1])
		{
			swp[i][0] = min(swp[i][0], swp[i-1][1]);
			swp[i][1] = min(swp[i][1], swp[i-1][0] + 1);
		}
	}
	return min(swp[n-1][0], swp[n-1][1]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		int a[n], b[n], a2[n], b2[n];
		for(int i=0; i<n; i++)
		{
			scanf("%d", a+i);
			a2[i] = a[i];
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d", b+i);
			b2[i] = b[i];
		}
		swap(a2[0], b2[0]);
		LL s1 = count_swaps(a, b, n);
		if(s1 >= n)
			printf("-1\n");
		else
			printf("%lld\n", s1);
	}
	return 0;
}

