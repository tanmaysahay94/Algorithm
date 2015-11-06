/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int f(ListNode* A) {
    int ret = 0;
    while (A) {
        ret++;
        A = A -> next;
    }
    return ret;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int len = f(A);
    B %= len;
    ListNode *last = A;
    while (last -> next) {
        last = last -> next;
    }
    last -> next = A;
    ListNode *first = A;
    ListNode *bFirst = A;
    for (int i = 1; i <= len - B; i++) {
        first = first -> next;
    }
    for (int i = 1; i < len - B; i++) {
        bFirst = bFirst -> next;
    }
    bFirst -> next = NULL;
    return first;
}
