#include <bits/stdc++.h>
using namespace std;

class trie
{
	public:
		unordered_map<char, trie *> next;
		int cnt;
		trie(): cnt(0) {}
		void add(string s, trie *t)
		{
			for (int i = 0; i < (int) s.size(); i++)
			{
				char c = s[i];
				if (t->next.count(c) == 0)
					t->next[c] = new trie();
				t = t->next[c];
				t->cnt+=1;
			}
		}
		void dfs(trie *t, string path)
		{
			if (t -> cnt >= 0)
			cout << path << ' ' << t -> cnt << endl;
			for (auto foo: t -> next)
				dfs(foo.second, path + foo.first);
		}
		bool search(string word, trie *t)
		{
			for (auto w: word)
				if (t -> next.count(w) == 0)
					return false;
				else
					t = t -> next[w];
			return true;
		}
};

int main()
{
	trie *t = new trie();
	t -> cnt = -1;
	t -> add(string("tamnay"), t);
	t -> add(string("tanmay"), t);
	t -> dfs(t, "");
	cout << t -> search("tanmay", t) << endl;
	cout << t -> search("tanbay", t) << endl;
	return 0;
}
