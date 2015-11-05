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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	string home, away;
	cin >> home >> away;
	LL n;
	cin >> n;
	map<LL, LL> hme, awy;
	map<LL, bool> hcard, acard;
	vector<pair<LL, pair<LL, string> > > answer;
	for (LL i = 0; i < n; i++)
	{
		LL minute, num;
		string side, card;
		cin >> minute >> side >> num >> card;
		if (side == "h")
		{
			if (hcard.find(num) != hcard.end())
				continue;
			if (card == "r")
			{
				answer.pb(mp(minute, mp(num, home)));
				hcard[num] = true;
				continue;
			}
			if (hme.find(num) != hme.end())
			{
				answer.pb(mp(minute, mp(num, home)));
				hcard[num] = true;
			}
			else
				hme[num] = minute;
		}
		else
		{
			if (acard.find(num) != acard.end())
				continue;
			if (card == "r")
			{
				answer.pb(mp(minute, mp(num, away)));
				acard[num] = true;
				continue;
			}
			if (awy.find(num) != awy.end())
			{
				answer.pb(mp(minute, mp(num, away)));
				acard[num] = true;
			}
			else
				awy[num] = minute;
		}
	}
	sortv(answer);
	for (LL i = 0; i < sz(answer); i++)
		cout << answer[i].s.s << " " << answer[i].s.f << " " << answer[i].f << endl;
	return 0;
}
