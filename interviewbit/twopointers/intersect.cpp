vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0, j = 0;
    vector<int> ret;
    while (i < (int) A.size() and j < (int) B.size()) {
        if (A[i] == B[j]) {
            ret.push_back(A[i]);
            i++, j++;
        }
        else if (A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return ret;
}
