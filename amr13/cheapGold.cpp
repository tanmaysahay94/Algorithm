
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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int c;
	SI(c);
	vector<int> a(c+1);
	a[0] = INT_MAX;
	for(int i=1; i<=c; i++)
	{
		SI(a[i]);
		a[i] = min(a[i], a[i-1]);
	}
	int n, num;
	SI(n);
	int mx = INT_MIN;
	for(int i=0; i<n; i++)
	{
		SI(num);
		mx = max(mx, num);
	}
	printf("%d\n", a[mx]);
	return 0;
}
