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
	LL ax, ay, bx, by;
	SLL(ax); SLL(ay); SLL(bx); SLL(by);
	LL count2[2][2] = {0}, count3[2][2] = {0};
	LL val[2][2];
	val[0][0] = ax, val[0][1] = ay, val[1][0] = bx, val[1][1] = by;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			while (val[i][j] % 2 == 0)
			{
				val[i][j] /= 2;
				count2[i][j]++;
			}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			while (val[i][j] % 3 == 0)
			{
				val[i][j] /= 3;
				count3[i][j]++;
			}
	if (val[0][0] * val[0][1] != val[1][0] * val[1][1])
	{
		cout << "-1\n";
		return 0;
	}
	LL steps = 0;
	if (count3[0][0] + count3[0][1] != count3[1][0] + count3[1][1])
	{
		if (count3[0][0] + count3[0][1] > count3[1][0] + count3[1][1])
		{
			LL diff = count3[0][0] + count3[0][1] - count3[1][0] - count3[1][1];
			if (count3[0][0] >= diff)
			{
				count3[0][0] -= diff;
				steps += diff;
				count2[0][0] += diff;
			}
			else
			{
				LL a = diff - count3[0][0];
				count2[0][0] += count3[0][0];
				steps += count3[0][0];
				count3[0][0] = 0;
				count3[0][1] -= a;
				count2[0][1] += a;
				steps += a;
			}
		}
		else
		{
			LL diff = count3[1][0] + count3[1][1] - count3[0][0] - count3[0][1];
			if (count3[1][0] >= diff)
			{
				count3[1][0] -= diff;
				steps += diff;
				count2[1][0] += diff;
			}
			else
			{
				LL a = diff - count3[1][0];
				count2[1][0] += count3[1][0];
				steps += count3[1][0];
				count3[1][0] = 0;
				count3[1][1] -= a;
				count2[1][1] += a;
				steps += a;
			}
		}
	}
	if (count2[0][0] + count2[0][1] != count2[1][0] + count2[1][1])
	{
		if (count2[0][0] + count2[0][1] > count2[1][0] + count2[1][1])
		{
			LL diff = count2[0][0] + count2[0][1] - count2[1][0] - count2[1][1];
			if (count2[0][0] >= diff)
			{
				count2[0][0] -= diff;
				steps += diff;
			}
			else
			{
				LL a = diff - count2[0][0];
				steps += count2[0][0];
				count2[0][0] = 0;
				count2[0][1] -= a;
				steps += a;
			}
		}
		else
		{
			LL diff = count2[1][0] + count2[1][1] - count2[0][0] - count2[0][1];
			if (count2[1][0] >= diff)
			{
				count2[1][0] -= diff;
				steps += diff;
			}
			else
			{
				LL a = diff - count2[1][0];
				steps += count2[1][0];
				count2[1][0] = 0;
				count2[1][1] -= a;
				steps += a;
			}
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			val[i][j] = val[i][j] * pow(2, count2[i][j]) * pow(3, count3[i][j]);
	printf("%lld\n%lld %lld\n%lld %lld\n", steps, val[0][0], val[0][1], val[1][0], val[1][1]);
	return 0;
}
