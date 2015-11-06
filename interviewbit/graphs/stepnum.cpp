bool stepNum(int n) {
    int a = n % 10;
    n /= 10;
    int b;
    while (n) {
        b = n % 10;
        n /= 10;
        if (abs(a - b) != 1) {
            return false;
        }
        a = b;
    }
    return true;
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ret;
    for (int i = A; i <= B; i++) {
        if (stepNum(i)) {
            ret.push_back(i);
        }
    }
    return ret;
}