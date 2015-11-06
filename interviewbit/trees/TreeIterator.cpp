/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode* > S;
TreeNode* cur;

BSTIterator::BSTIterator(TreeNode *root) {
    cur = root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return cur or S.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if (cur) {
        S.push(cur);
        cur = cur -> left;
        next();
    }
    else {
        if (S.size()) {
            cur = S.top();
            S.pop();
            int ret = cur -> val;
            cur = cur -> right;
            return ret;
        }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
