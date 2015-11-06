struct trie {
    trie* next[26];
    int cnt;
    trie() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        cnt = 0;
    }
};

void insert(trie *head, string& S) {
    trie *t = head;
    for (auto s: S) {
        if (not t -> next[s - 'a']) {
            t -> next[s - 'a'] = new trie();
        }
        t = t -> next[s - 'a'];
        t -> cnt++;
    }
}

string find(trie *head, string& S) {
    string ret = "";
    trie *t = head;
    for (auto s: S) {
        t = t -> next[s - 'a'];
        ret += s;
        if (t -> cnt == 1) {
            break;
        }
    }
    return ret;
}

vector<string> Solution::prefix(vector<string> &A) {
    trie *head = new trie();
    vector<string> ret;
    for (auto a: A) {
        insert(head, a);
    }
    for (auto a: A) {
        ret.push_back(find(head, a));
    }
    return ret;
}