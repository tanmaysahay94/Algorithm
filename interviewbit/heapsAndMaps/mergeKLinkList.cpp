/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<int> pq;
    for (auto a: A) {
        ListNode *it = a;
        while (it) {
            pq.push(-(it -> val));
            it = it -> next;
        }
    }
    ListNode *head, *tail;
    head = tail = NULL;
    while (!pq.empty()) {
        int val = pq.top() * -1;
        pq.pop();
        if (head == tail and head == NULL) {
            head = tail = new ListNode(val);
        }
        else {
            tail -> next = new ListNode(val);
            tail = tail -> next;
        }
    }
    return head;
}
