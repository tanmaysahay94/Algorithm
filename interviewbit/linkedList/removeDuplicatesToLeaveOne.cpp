/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* t = A;
    while (t) {
        if (t -> next) {
            if (t -> val == t -> next -> val) {
                t -> next = t -> next -> next;
            }
            else {
                t = t -> next;
            }
        }
        else {
            t = t -> next;
        }
    }
    return A;
}
