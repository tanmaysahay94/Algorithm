int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    unordered_set<string> u_set;
    for (auto word: dictV) {
        u_set.insert(word);
    }
    queue<pair<string, int> > Q;
    Q.push(make_pair(start, 1));
    while (Q.size()) {
        pair<string, int> curr = Q.front();
        Q.pop();
        string currWord = curr.first;
        int currLength = curr.second;
        if (currWord == end) {
            return currLength;
        }
        for (int i = 0; i < (int) currWord.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                char tmp = currWord[i];
                if (tmp != c) {
                    currWord[i] = c;
                }
                if (u_set.count(currWord)) {
                    Q.push(make_pair(currWord, currLength + 1));
                    u_set.erase(currWord);
                }
                currWord[i] = tmp;
            }
        }
    }
    return 0;
}