/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *dummy = new ListNode(0);
    dummy -> next = A;
    ListNode *prev = dummy;
    ListNode *it = A;
    while (prev -> next) {
        int cnt = 0;
        while (it -> next and it -> val == it -> next -> val) {
            it = it -> next;
            cnt++;
        }
        if (cnt) {
            prev -> next = it -> next;
        }
        else {
            prev = prev -> next;
        }
        it = it -> next;
    }
    return dummy -> next;
}
