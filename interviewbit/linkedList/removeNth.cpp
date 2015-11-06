/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode *L) {
    int ret = 0;
    while (L) {
        L = L -> next;
        ret++;
    }
    return ret;
}
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = len(A);
    if (l <= B) {
        return A -> next;
    }
    ListNode *tmp = A;
    for (int i = 1; i < l - B; i++) {
        tmp = tmp -> next;
    }
    tmp -> next = tmp -> next -> next;
    return A;
}
