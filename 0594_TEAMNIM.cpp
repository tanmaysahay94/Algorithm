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

bool abab(VI& v)
{
	return v[0] ^ v[1] ^ v[2];
}

bool aabb(VI& v)
{
	return !(v[0] % 2 == 0 and v[0] == v[1] and (v[1] == v[2] or v[1] + 1 == v[2]));
}

bool abba(VI& v)
{
	if (v[0] % 2 == 0 and v[0] + 1 == v[1] and v[1] == v[2])
		return true;
	if (v[0] % 2 == 0 and v[0] == v[1] and v[2] > v[1])
		return true;
	if (v[0] % 2 == 0 and v[0] + 1 == v[1] and v[2] > v[0])
		return true;
	return false;
}

int main()
{
	int t;
	VI v(3);
	vector<string> str(4);
	si(t);
	while (t--)
	{
		bool ans;
		for (int i = 0; i < 3; i++)
			si(v[i]);
		sortv(v);
		for (int i = 0; i < 4; i++)
			cin >> str[i];
		if (str[0][0] == 'E' or str[0][0] == 'N')
		{
			if (str[1][0] == 'E' or str[1][0] == 'N')
				ans = aabb(v);
			if (str[2][0] == 'E' or str[2][0] == 'N')
				ans = abab(v);
			if (str[3][0] == 'E' or str[3][0] == 'N')
				ans = abba(v);
		}
		else
		{
			if (str[1][0] == 'A' or str[1][0] == 'B')
				ans = !aabb(v);
			if (str[2][0] == 'A' or str[2][0] == 'B')
				ans = !abab(v);
			if (str[3][0] == 'A' or str[3][0] == 'B')
				ans = !abba(v);
		}
		if (ans)
			printf("Elayne/Nynaeve\n");
		else
			printf("Aviendha/Birgitte\n");
	}
	return 0;
}
