int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far = 0, max_ending_here = A[0], mx = A[0];
    for (int i = 1; i < (int) A.size(); i++) {
        mx = max(mx, A[i]);
        max_ending_here = max(0, max_ending_here + A[i]);
        max_so_far = max(max_ending_here, max_so_far);
    }
    if (max_so_far == 0) return mx;
    return max_so_far;
}
