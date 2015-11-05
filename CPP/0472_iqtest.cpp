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
	int c1, c2;
	vector<string> v;
	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		v.pb(s);
	}
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++)
		{
			c1 = c2 = 0;
			for (int l = j; l <= j + 1; l++)
				for (int m = i; m <= i +1 ; m++)
					c1 += v[m][l]=='.';
			for (int l = j; l <= j + 1; l++)
				for (int m = i; m <= i +1 ; m++)
					c2 += v[m][l]=='#';
			if (c1 >= 3 or c2 >= 3)
				break;
		}
		if (c1 >= 3 or c2 >= 3)
			break;
	}
	if (c1 >= 3 or c2 >= 3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
