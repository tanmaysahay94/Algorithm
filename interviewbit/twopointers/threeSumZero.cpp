vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > ret;
    set<vector<int> > present;
    sort(A.begin(), A.end());
    for (int i = 0; i < (int) A.size(); i++) {
        for (int j = i + 1; j < (int) A.size(); j++) {
            if (binary_search(A.begin() + j + 1, A.end(), -(A[i] + A[j]))) {
                vector<int> foo;
                foo.push_back(A[i]);
                foo.push_back(A[j]);
                foo.push_back(-(A[j] + A[i]));
                if (present.count(foo) == 0) {
                    ret.push_back(foo);
                    present.insert(foo);
                }
            }
        }
    }
    return ret;
}
