int Solution::maxp3(vector<int> &A) {
    int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
    for (int i = 0; i < (int) A.size(); i++) {
        m3 = max(m3, A[i]);
    }
    int cnt = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] == m3) {
            cnt++;
        }
    }
    if (cnt >= 3) {
        m1 = m2 = m3;
    }
    else if (cnt == 2) {
        m2 = m3;
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] != m2 and A[i] != m3) {
                m1 = max(m1, A[i]);
            }
        }
    }
    else {
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] != m3) {
                m2 = max(m2, A[i]);
            }
        }
        cnt = 0;
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] == m2) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            m1 = m2;
        }
        else {
            for (int i = 0; i < (int) A.size(); i++) {
                if (A[i] != m3 and A[i] != m2) {
                    m1 = max(m1, A[i]);
                }
            }
        }
    }
    int ans = m1 * m2 * m3;
    m1 = INT_MAX, m2 = INT_MAX;
    for (int i = 0; i < (int) A.size(); i++) {
        m1 = min(m1, A[i]);
    }
    cnt = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] == m1) {
            cnt++;
        }
    }
    if (cnt >= 2) {
        m2 = m1;
    }
    else {
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] != m1) {
                m2 = min(m2, A[i]);
            }
        }
    }
    ans = max(ans, m1 * m2 * m3);
    return ans;
}