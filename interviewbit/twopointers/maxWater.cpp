int Solution::maxArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int ret = INT_MIN;
    int l = 0, r = n - 1;
    while (l <= r) {
        int temp = (r - l) * min(A[l], A[r]);
        ret = max(ret, temp);
        if (A[l] > A[r]) {
            r--;
        }
        else {
            l++;
        }
    }
    return ret;
}
