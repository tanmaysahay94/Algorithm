#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

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

struct trie
{
	trie *next[26];
	trie() {
		memset(next, 0, sizeof(next));
	}
};

LL isSet, toAdd;
trie *root = new trie;

void trie_insert(trie *tr, string& str, int curr, int end)
{
	if (curr <= end)
	{
		if (tr->next[str[curr] - 'a'] == 0)
		{
			if (not isSet)
				toAdd = curr+1, isSet = 1;
			tr->next[str[curr] - 'a'] = new trie;
		}
		trie_insert(tr->next[str[curr] - 'a'], str, curr+1, end);
	}
	else
	{
		if (not isSet)
			toAdd = curr, isSet = 1;
	}
}

int main()
{
	int t;
	si(t);
	for (int test = 1; test <= t; test++)
	{
		int n;
		LL ans = 0;
		string str;
		si(n);
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int len = str.length();
			isSet = 0;
			toAdd = 1;
			trie_insert(root, str, 0, len-1);
			ans += toAdd;
		}
		printf("Case #%d: %lld\n", test, ans);
		delete root;
		trie *tmp = new trie;
		root = tmp;
	}
	return 0;
}
