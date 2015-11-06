/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* A) {
    int ret = 0;
    while (A) {
        A = A -> next;
        ret++;
    }
    return ret;
}

ListNode* Solution::reorderList(ListNode* A) {
    if (len(A) < 3) {
        return A;
    }
    vector<int> V;
    ListNode* t = A;
    while (t) {
        V.push_back(t -> val);
        t = t -> next;
    }
    int l = 0, r = len(A) - 1;
    ListNode *head, *tail;
    head = tail = NULL;
    while (l < r) {
        int v1 = V[l], v2 = V[r];
        if (head == tail and head == NULL) {
            head = tail = new ListNode(v1);
        }
        else {
            tail -> next = new ListNode(v1);
            tail = tail -> next;
        }
        if (head == tail and head == NULL) {
            head = tail = new ListNode(v2);
        }
        else {
            tail -> next = new ListNode(v2);
            tail = tail -> next;
        }
        l++, r--;
    }
    if (l == r) {
        int v1 = V[l];
        if (head == tail and head == NULL) {
            head = tail = new ListNode(v1);
        }
        else {
            tail -> next = new ListNode(v1);
            tail = tail -> next;
        }
    }
    return head;
}
