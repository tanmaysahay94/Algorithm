/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    stack<TreeNode*> S;
    if (not A) {
        return v;
    }
    S.push(A);
    while (S.size()) {
        TreeNode* tmp = S.top();
        v.push_back(tmp -> val);
        S.pop();
        if (tmp -> left) {
            S.push(tmp -> left);
        }
        if (tmp -> right) {
            S.push(tmp -> right);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
