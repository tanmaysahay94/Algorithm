/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int size(ListNode* A) {
    int ret = 0;
    while (A) {
        A = A -> next;
        ret++;
    }
    return ret;
}

TreeNode* generate(ListNode* &A, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode* L = generate(A, start, mid - 1);
    TreeNode* T = new TreeNode(A -> val);
    T -> left = L;
    A = A -> next;
    TreeNode* R = generate(A, mid + 1, end);
    T -> right = R;
    return T;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = size(A);
    return generate(A, 0, len - 1);
}
