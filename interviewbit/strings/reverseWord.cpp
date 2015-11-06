void Solution::reverseWords(string &A) {
    int start = 0, end = A.length() - 1;
    while (A[start] == ' ') {
        start++;
    }
    while (A[end] == ' ') {
        end--;
    }
    vector<string> words;
    string tmp;
    int i = start;
    while (i <= end) {
        if (A[i] != ' ') {
            tmp.push_back(A[i]);
            i++;
        }
        else {
            words.push_back(tmp);
            tmp = string("");
            int j = i;
            while (A[j] == ' ' and j <= end) {
                j++;
            }
            i = j;
        }
    }
    words.push_back(tmp);
    reverse(words.begin(), words.end());
    A = string("");
    for (int i = 0; i < (int) words.size(); i++) {
        A += words[i];
        if (i == (int) words.size() - 1) {
            continue;
        }
        A.push_back(' ');
    }
}
