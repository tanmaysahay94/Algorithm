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
		char s[100100];
		scanf("%s", s);
		int sum = 0;
		int i;
		for(i=0; s[i]; i++)
			sum += s[i] - '0';
		int md = sum % 9;
		int ans = 10;
		if(md == 0)
			ans = 0;
		else
		{
			if(sum - 1 >= md || (md == sum && i == 1))
				ans = md;
			ans = min(ans, 9-md);
		}
		printf("%d\n", ans);
	}
	return 0;
}
