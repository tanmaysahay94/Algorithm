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

LL lowestCommonAncestor(LL a, LL b)
{
	while (a != b)
	{
		if (a > b)
			a >>= 1;
		else
			b >>= 1;
	}
	return a;
}

int main()
{
	// Given: An infinite-sized complete binary tree
	// Input: 2 nodes in the binary tree
	// Output: lowestCommonAncestor of the 2 nodes
	LL a, b;
	cin >> a >> b;
	cout << lowestCommonAncestor(a, b) << endl;
	return 0;
}
