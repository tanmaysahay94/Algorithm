int inDecOrder(vector<int>& num) {
    for (int i = 1; i < (int) num.size(); i++) {
        if (num[i] > num[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void Solution::nextPermutation(vector<int> &num) {
    int n = num.size();
    if(n <= 1) {
        return;
    }
    if (inDecOrder(num)) {
        reverse(num.begin(), num.end());
        return;
    }
    int i = n - 2;
    // i is the first index before ascending subarray
    while (i >= 0 && num[i] >= num[i + 1]) {
        --i;
    }
    int j = n - 1;
    // j is the first index before descending subarray
    while (j >= 0 && num[j] <= num[i]) {
        --j;
    }
    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
}
