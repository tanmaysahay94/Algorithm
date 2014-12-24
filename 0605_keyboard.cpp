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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	vector<string> v;
	v.pb(string("qwertyuiop"));
	v.pb(string("asdfghjkl;"));
	v.pb(string("zxcvbnm,./"));
	string dir;
	cin >> dir;
	int move;
	if (dir == "R")
		move = -1;
	else
		move = 1;
	string msg;
	cin >> msg;
	for (int i = 0; i < (int) msg.length(); i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 10; k++)
				if (v[j][k] == msg[i])
				{
					int idx;
					if (k + move < 0)
						idx = 9;
					else
						idx = (k + move) % 10;
					cout << v[j][idx];
				}
	cout << endl;
	return 0;
}
