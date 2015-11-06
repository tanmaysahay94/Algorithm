bool isBlankSpace(const string &A) {
    for (int i = 0; i < (int) A.length(); i++) {
        if (A[i] != ' ') {
            return false;
        }
    }
    return true;
}
bool isChar(char a) {
    if (a >= 'a' and a <= 'z') {
        return true;
    }
    if (a >= 'A' and a <= 'Z') {
        return true;
    }
    return false;
}
int Solution::lengthOfLastWord(const string &A) {
    if (isBlankSpace(A)) {
        return 0;
    }
    int idx = A.length() - 1;
    while (idx >= 0 and A[idx] == ' ') {
        idx--;
    }
    int start = idx;
    while (start >= 0 and isChar(A[start])) {
        start--;
    }
    return idx - start;
}
