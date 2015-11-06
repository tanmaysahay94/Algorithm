int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    vector<int> profit(n);
    int max_sell = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > max_sell) {
            max_sell = A[i];
        }
        profit[i] = max(profit[i + 1], max_sell - A[i]);
    }
    int min_price = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min_price) {
            min_price = A[i];
        }
        profit[i] = max(profit[i - 1], profit[i] + A[i] - min_price);
    }
    return profit[n - 1];
}