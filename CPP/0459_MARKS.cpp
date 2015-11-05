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

int main()
{
	char subject;
	LL n, marks;
	SLL(n);
	getchar();
	VLL students(5);
	vector<VLL> v(5, VLL (105, 0)), ans(5);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &subject);
		SLL(marks);
		getchar();
		v[subject - 'A'][marks]++;
		students[subject - 'A']++;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 105; j++)
			if (v[i][j] and (double)v[i][j] >= (double)students[i]/(double)10)
				ans[i].pb(j);
	for (int i = 0; i < 5; i++)
	{
		if (ans[i].empty())
			printf("Nothing Unusual\n");
		else
		{
			for (int j = 0; j < ans[i].size(); j++)
				printf("%lld ", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
