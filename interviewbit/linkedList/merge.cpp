/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
/*    ListNode *ret;
    if (A -> val < B -> val) {
        ret = new ListNode(A -> val);
        A = A -> next;
    }
    else {
        ret = new ListNode(B -> val);
        B = B -> next;
    }
    ListNode *ans = ret;
    while (A and B) {
        ListNode *tmp;
        if (A -> val < B -> val) {
            tmp = new ListNode(A -> val);
            A = A -> next;
        }
        else {
            tmp = new ListNode(B -> val);
            B = B -> next;
        }
        ret -> next = tmp;
        ret = ret -> next;
    }
    while (A) {
        ListNode *tmp = new ListNode(A -> val);
        ret -> next = tmp;
        ret = ret -> next;
        A = A -> next;
    }
    while (B) {
        ListNode *tmp = new ListNode(B -> val);
        ret -> next = tmp;
        ret = ret -> next;
        B = B -> next;
    }
    return ans;*/
    
    /**Recursive shizzz*/
    if (A == NULL) {
        return B;
    }
    if (B == NULL) {
        return A;
    }
    if (A -> val < B -> val) {
        A -> next = mergeTwoLists(A -> next, B);
        return A;
    }
    else {
        B -> next = mergeTwoLists(B -> next, A);
        return B;
    }
}
