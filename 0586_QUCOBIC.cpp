#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t;
	sll(t);
	while (t--)
	{
		LL sec, time;
		sll(time); sll(sec);
		LL hour = time/100;
		LL min = time%100;
		LL currSec = hour*3600 + min*60 + 59 + sec;
		currSec %= 86400;
		hour = currSec/3600;
		currSec %= 3600;
		min = currSec/60;
		currSec %= 60;
		if (hour == 0 and min == 0)
			if (currSec <= 58)
				printf("2359\n");
			else
				printf("0000\n");
		else
		{
			if (hour < 10)
				printf("0%lld", hour);
			else
				printf("%lld", hour);
			if (min < 10)
				printf("0%lld\n", min);
			else
				printf("%lld\n", min);
		}
	}
	return 0;
}
