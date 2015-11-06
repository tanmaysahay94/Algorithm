bool isPossible(long long val, vector<long long>& a, long long b) {
    int idx = 0;
    long long sum = 0;
    long long ppl = 1;
    while (idx < (int) a.size()) {
        if (sum + a[idx] <= val) {
            sum += a[idx];
        }
        else {
            sum = 0;
            if (a[idx] > val) {
                return false;
            }
            else {
                sum = a[idx];
                ppl++;
                if (ppl > b) {
                    return false;
                }
            }
        }
        idx++;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    vector<long long> a;
    for (auto it: A) {
        a.push_back(it);
    }
    long long b = B;
    long long low = 0;
    long long high = 1e18;
    while (high - low > 1) {
        long long mid = (low + high) >> 1;
        if (isPossible(mid, a, b)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    if (not isPossible(high, a, b) or b > (int) a.size()) {
        high = -1;
    }
    return high;
}
