vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 0;
    int cnt = 0;
    int max_len = 0;
    int beg = 0, end = 0;
    vector<int> ret;
    while (i < n) {
        if (cnt + (A[i] == 0) > B) {
            int temp_len = i - j;
            if (temp_len > max_len) {
                max_len = temp_len;
                beg = j;
                end = i - 1;
            }
            while (i > j and cnt + (A[i] == 0) > B) {
                cnt -= (A[j] == 0);
                j++;
            }
            cnt += A[i] == 0;
        }
        else {
            cnt += A[i] == 0;
        }
        i++;
    }
    int temp_len = i - j;
    if (temp_len > max_len) {
        max_len = temp_len;
        beg = j;
        end = i - 1;
    }
    for (int i = beg; i <= end; i++) {
        ret.push_back(i);
    }
    return ret;
}
