vector<int> Solution::repeatedNumber(const vector<int> &V) {
    long long sum = 0;
    long long squareSum = 0;
    long long temp;
    for (int i = 0; i < (int) V.size(); i++) {
        temp = V[i];
        sum += temp;
        sum -= (i + 1);
        squareSum += temp * temp;
        squareSum -= ((long long) (i + 1) * (long long) (i + 1));
    }   
    squareSum /= sum;
    int A = (int) ((sum + squareSum) / 2);
    int B = squareSum - A;
    vector<int> ret;
    ret.push_back(A);
    ret.push_back(B);
    return ret;
}
