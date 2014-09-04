#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

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
	bool pass = true;
	int n, i;
	double a, f, curr = 0;
	string s;
	cin >> n >> s >> a >> f;
	for (i = 0; s[i]; i++)
	{
		if (s[i] == 'L')
			curr -= a;
		else
			curr += a;
		if (abs(curr) >= f)
		{
			pass = false;
			break;
		}
	}
	if (pass) 
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}
