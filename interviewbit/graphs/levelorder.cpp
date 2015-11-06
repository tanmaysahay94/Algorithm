/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse(TreeNode* A, vector<vector<int> > &ret, int lvl) {
    if (A == NULL) {
        return;
    }
    if (lvl > (int) ret.size()) {
        vector<int> tmp;
        tmp.push_back(A -> val);
        ret.push_back(tmp);
    }
    else {
        ret[lvl - 1].push_back(A -> val);
    }
    traverse(A -> left, ret, lvl + 1);
    traverse(A -> right, ret, lvl + 1);
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ret;
    traverse(A, ret, 1);
    return ret;
}