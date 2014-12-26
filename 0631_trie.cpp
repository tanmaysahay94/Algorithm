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

char str[111111];

struct trie
{ 
	int idx1, idx2;
	trie *next[26];
	trie()
	{ 
		idx1 = -1;
		idx2 = -1;
		memset(next, 0, sizeof(next));
	}
};

trie *root = new trie;

void trie_insert(trie *tr, char *str)
{ 
	if(*str != '\0')
	{ 
		if(tr->next[*str - 'a'] == 0)
			tr->next[*str-'a'] = new trie;
		trie_insert(tr->next[*str - 'a'], str + 1);
	}
}
void dfs(trie *tr)
{ 
	int k = 0;
	tr->idx1 = 0;
	tr->idx2 = 1;
	for(int i = 0;i < 26; i++)
		if(tr->next[i] != 0)
		{ 
			k = 1;
			dfs(tr->next[i]);
			trie *son = tr->next[i];
			if(son->idx1 == 0)
				tr->idx1 = 1;
			if(son->idx2 == 1)
				tr->idx2 = 0;
		}
	if(k == 0)
		tr->idx2=0;
}

int main()
{ 
	int n, k;
	bool flag1 = false, flag2 = false;
	si(n); si(k);
	for(int i = 0; i < n; i++)
	{ 
		scanf("%s", str);
		trie_insert(root, str);
	}
	dfs(root);
	if(root->idx1 == 1)
		flag1 = true;
	if(root->idx2 == 0)
		flag2 = true;
	if(flag1 && flag2)
		printf("First\n");
	else if(flag1)
		if(k & 1)
			printf("First\n");
		else
			printf("Second\n");
	else
		printf("Second\n");
}
