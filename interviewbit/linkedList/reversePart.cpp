/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *helper(ListNode* head, int sz) {
    if (sz <= 1) {
        return head;
    }
    ListNode *cur = head, *nextNode = head -> next, *tmp;
    for (int i = 0; i < sz - 1; i++) {
        tmp = nextNode -> next;
        nextNode -> next = cur;
        cur = nextNode;
        nextNode = tmp;
    }
    head -> next = nextNode;
    return cur;
}

ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode *prev = dummy;
    ListNode *cur = head;
    int idx = 1;
    while (idx < m) {
        prev = cur;
        cur = cur -> next;
        idx++;
    }
    ListNode *endSubList = helper(cur, n - m + 1);
    prev -> next = endSubList;
    return dummy -> next;
}