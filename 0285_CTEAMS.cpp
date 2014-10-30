#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

struct cmp
{
	bool operator() (const pair<LL, LL>& a, const pair<LL, LL>& b)
	{
		return a.f > b.f;
	}
};

int main()
{
	priority_queue<pair<LL, LL> > young;
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, cmp> old;
	pair<LL, LL> temp;
	LL n, a, r, youngRating = 0LL, oldRating = 0LL;
	SLL(n);
	SLL(a); SLL(r);
	young.push(mp(a, r));
	youngRating += young.top().s;
	printf("%lld\n", abs(youngRating - oldRating));
	for (int i = 2; i <= n; i++)
	{
		SLL(a); SLL(r);
		if (i & 1)		//add to young team
		{
			if (a < old.top().f)
			{
				young.push(mp(a, r));
				youngRating += r;
			}
			else
			{
				temp = old.top();
				old.pop();
				oldRating -= temp.s;
				old.push(mp(a, r));
				oldRating += r;
				young.push(temp);
				youngRating += temp.s;
			}
		}
		else			//add to old team
		{
			if (a > young.top().f)
			{
				old.push(mp(a, r));
				oldRating += r;
			}
			else
			{
				temp = young.top();
				young.pop();
				youngRating -= temp.s;
				young.push(mp(a, r));
				youngRating += r;
				old.push(temp);
				oldRating += temp.s;
			}
		}
		printf("%lld\n", abs(youngRating - oldRating));
	}
	return 0;
}
