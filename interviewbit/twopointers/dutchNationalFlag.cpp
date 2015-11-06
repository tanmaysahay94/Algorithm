void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> cnt(3);
    for (auto a: A) {
        cnt[a]++;
    }
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            A[idx++] = i;
        }
    }
}
