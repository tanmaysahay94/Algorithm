#include <bits/stdc++.h>

using namespace std;

class trie
{
	public:
		trie* next[26];
		bool isEnd;
		trie()
		{
			for (int i = 0; i < 26; i++)
				next[i] = NULL;
			isEnd = false;
		}
};

bool insert(trie* t, string& S)
{
	bool ret = false;
	bool hasPassedAnEnd = false;
	for (int i = 0; i < (int) S.size(); i++)
	{
		int idx = S[i] - 'a';
		if (not t -> next[idx])
		{
			t -> next[idx] = new trie();
			ret = true;
		}
		t = t -> next[idx];
		if (t -> isEnd)
			hasPassedAnEnd = true;
		if (i == ((int) S.size()) - 1)
			t -> isEnd = true;
	}
	return ret and not hasPassedAnEnd;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		trie *t = new trie();
		int n;
		cin >> n;
		bool possible = true;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			possible = possible and insert(t, s);
		}
		if (possible)
			cout <<"YES\n";
		else
			cout <<"NO\n";
	}
	return 0;
}
