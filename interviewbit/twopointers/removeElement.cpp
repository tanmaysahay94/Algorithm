int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int placeAt = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] != B) {
            A[placeAt++] = A[i];
        }
    }
    return placeAt;
}