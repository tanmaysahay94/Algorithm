#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int misha = max((3*a)/10, a - (a*c)/250);
	int vasya = max((3*b)/10, b - (b*d)/250);
	if (misha > vasya)
		cout << "Misha\n";
	else if (misha < vasya)
		cout << "Vasya\n";
	else
		cout << "Tie\n";
	return 0;
}
