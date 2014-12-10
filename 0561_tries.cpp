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

class trie {
	public:
		trie *child[2];
		trie() {
			child[0] = child[1] = NULL;
		}
		void insert(int val, int count = 32) {
			if (count) {
				bool bit = val & 1;
				if (child[bit] == NULL)
					child[bit] = new trie;
				child[bit]->insert(val>>1, count-1);
			}
		}
		int find(int val, int count = 32, int ans = 0) {
			if(count) {
				bool bit = val & 1;
				if(child[1-bit] == NULL) {
					ans <<= 1;
					ans |= bit;
					return child[bit]->find(val>>1, count-1, ans);
				}
				else {
					ans <<= 1;
					ans |= (1-bit);
					return child[1-bit]->find(val>>1, count-1, ans);
				}
			}
			return ans;
		}
};

int reverseInt(int val);
void printtrie(trie *t);

int main()
{
	int t;
	SI(t);
	while (t--)
	{
		trie *bit_trie;
		bit_trie = new trie;
		bit_trie->insert(0);
		int n;
		SI(n);
		VI v(n);
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			SI(v[i]);
			tmp ^= v[i];
			bit_trie->insert(reverseInt(tmp), 32);
		}
		tmp = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			tmp ^= v[i];
			ans = max(ans, bit_trie->find(reverseInt(tmp))^tmp);;
		}
		printf("%d\n", ans);
		delete bit_trie;
	}
	return 0;
}

void printtrie(trie *t)
{
	if(t->child[0] != NULL)
	{
		printf("0");
		printtrie(t->child[0]);
	}
	if(t->child[1] != NULL)
	{
		printf("1");
		printtrie(t->child[1]);
	}
	return;
}

int reverseInt(int val)
{
	int rev = 0, i = 32;
	while (i--)
	{
		rev = rev << 1;
		rev |= val & 1;
		val = val >> 1;
	}
	return rev;
}
