bool isPossible(long long tm, long long K, long long T, vector<long long>& L) {
    int idx = 0;
    long long sum = 0;
    int ppl = 1;
    while (idx < (int) L.size()) {
        if (sum + T * L[idx] <= tm) {
            sum += T * L[idx];
        }
        else {
            sum = 0;
            if (T * L[idx] <= tm) {
                sum = T * L[idx];
            }
            else {
                return 0;
            }
            ppl++;
            if (ppl > K) {
                return 0;
            }
        }
        idx++;
    }
    return 1;
}

int Solution::paint(int K, int T, vector<int> &L) {
    long long mod = 10000003;
    long long low = 0, high = 1e18;
    vector<long long> l;
    for (int i = 0; i < (int) L.size(); i++) {
        l.push_back(L[i]);
    }
    long long k = K;
    long long t = T;
    while (low < high - 1) {
        long long mid = (low + high) / 2;
        if (isPossible(mid, k, t, l)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return (high % mod);
}
