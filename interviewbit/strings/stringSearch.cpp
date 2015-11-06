int Solution::strStr(const string &haystack, const string &needle) {
    if (needle.length() == 0) {
        return -1;
    }
    if (haystack.length() == 0) {
        return -1;
    }
    vector<int> table(needle.length() + 1);
    for (int i = 2; i < (int) table.size(); i++) {
        int j = table[i - 1];
        for (;;) {
            if (needle[j] == needle[i - 1]) {
                table[i] = j + 1;
                break;
            }
            else if (j == 0) {
                table[i] = 0;
                break;
            }
            else {
                j = table[j];
            }
        }
    }
    int m = needle.length();
    int n = haystack.length();
    int i(0), j(0);
    for (;;) {
        if (j == n) {
            return -1;
        }
        if (needle[i] == haystack[j]) {
            i++;
            j++;
            if (i == m) {
                return j - m;
            }
        }
        else if (i > 0) {
            i = table[i];
        }
        else j++;
    }
    return -1;
}
