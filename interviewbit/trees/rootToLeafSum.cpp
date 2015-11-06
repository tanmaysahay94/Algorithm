int process(vector<int>& num) {
    int sum = 0;
    for (int i = 0; i < (int) num.size(); i++) {
        sum = 10 * sum + num[i];
        sum %= 1003;
    }
    return sum;
}
void solve(TreeNode* A, vector<int>& num, int& sum) {
    if (not A) {
        return;
    }
    num.push_back(A -> val);
    if (not A -> left and not A -> right) {
        int val = process(num);
        sum += val;
        sum %= 1003;
        num.pop_back();
        return;
    }
    solve(A -> left, num, sum);
    solve(A -> right, num, sum);
    num.pop_back();
}
int Solution::sumNumbers(TreeNode* A) {
    int sum = 0;
    vector<int> num;
    solve(A, num, sum);
    return sum;
}
