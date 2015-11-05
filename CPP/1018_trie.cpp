#include <bits/stdc++.h>

using namespace std;

class trie 
{
	public:
		trie* next[26];
		trie() 
		{
			for (int i = 0; i < 26; i++) 
				next[i] = NULL;
		}
};

int add(trie* t, string& S)
{
	int ret = 0;
	bool found = false;
	for (int i = 0; i < (int) S.size(); i++)
	{
		int idx = S[i] - 'a';
		if (not t -> next[idx])
		{
			t -> next[idx] = new trie();
			if (not found)
			{
				found = true;
				ret = i + 1;
			}
		}
		t = t -> next[idx];
	}
	if (not found)
		ret = S.size();
	return ret;
}

int main()
{
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		int n;
		cin >> n;
		trie* t = new trie();
		string s;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			ans += add(t, s);
		}
		cout << "Case #" << T << ": " << ans << endl;
		delete[] t;
	}
	return 0;
}
