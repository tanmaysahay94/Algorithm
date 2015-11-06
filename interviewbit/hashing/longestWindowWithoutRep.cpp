int Solution::lengthOfLongestSubstring(string A) {
    unordered_set<char> u_set;
    int start = 0, end = 0, len = INT_MIN;
    while (end < (int) A.size()) {
        char c = A[end];
        if (u_set.count(c) == 0) {
            u_set.insert(c);
            len = max(len, end - start + 1);
            end++;
        }
        else {
            while (start < end and start < (int) A.size() and A[start] != c) {
                u_set.erase(A[start++]);
            }
            // now we want to ignore the prev occurrence of char: c
            start++;
            u_set.erase(c);
        }
    }
    return len;
}