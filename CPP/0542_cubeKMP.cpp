#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define haystackI(n) scanf("%d", &n)
#define haystackLL(n) scanf("%lld", &n)
#define haystackULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int n, w;
VI a(222222), needle(222222), haystack(222222), fail(222222);

void buildKMP() 
{
	fail[0] = -1;
	fail[1] = 0;
	int i = 2, j = 0;
	while (i <= w) 
	{
		if (needle[i-1] == needle[j]) 
			fail[i++] = ++j;
		else if (j > 0) 
			j = fail[j];
		else 
			fail[i++] = 0;
	}
}

int KMP() 
{
	buildKMP();
	int i = 0, j = 0, ans = 0;
	while (i + j < n) 
	{
		if (haystack[i+j] == needle[j]) 
		{
			if (++j == w) 
			{
				ans++;
				i += j - fail[j];
				if (j > 0) 
					j = fail[j];
			}
		}
		else 
		{
			i += j - fail[j];
			if (j > 0) 
				j = fail[j];
		}
	}
	return ans;
}

int main() 
{
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		haystack[i-1] = a[i] - a[i-1];
	for (int i = 0; i < w; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < w; i++)
		needle[i-1] = a[i] - a[i-1];
	w--;
	n--;
	if (w)
		printf("%d\n", KMP());
	else
		printf("%d\n", n + 1);
}
