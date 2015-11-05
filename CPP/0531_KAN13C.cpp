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

char w[4444444];
int i;
VI fail(4444444);

void failureFunction(char *a, VI& fail)
{
	LL len = strlen(a);
	LL i = 1, j = 0;
	fail[0] = 0;
	while (i < len)
	{
		if (a[i] == a[j])
		{
			if (i)
				fail[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j)
				j = fail[j - 1];
			else
			{
				fail[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	while (1)
	{
		scanf("%s", w);
		if (strcmp(w, "End") == 0)
			break;
		failureFunction(w, fail);
		LL len = strlen(w);
		for (LL i = 0; i < len; i++)
			printf("%d ", fail[i]);
		cout << endl;
	}
	return 0;
}
