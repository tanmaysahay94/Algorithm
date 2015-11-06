vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> tmp;
    tmp.push_back(0);
    for (int i = 0; i < (int) A.size(); i++) {
        tmp.push_back(A[i]);
    }
    int sz = tmp.size();
    int carry = 1;
    for (int i = sz - 1; i >= 0; i--) {
        int foo = tmp[i] + carry;
        tmp[i] = foo % 10;
        carry = foo / 10;
    }
    int i = 0;
    while (tmp[i] == 0) {
        i++;
    }
    vector<int> ret;
    for (; i < sz; i++) {
        ret.push_back(tmp[i]);
    }
    return ret;
}