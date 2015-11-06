/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode *, RandomListNode *> u_map;
    RandomListNode* T = A;
    RandomListNode* head, *tail;
    head = tail = NULL;
    while (T) {
        RandomListNode* tmp = new RandomListNode(T -> label);
        u_map[T] = tmp;
        if (head == tail and head == NULL) {
            head = tail = tmp;
        }
        else {
            tail -> next = tmp;
            tail = tail -> next;
        }
        T = T -> next;
    }
    RandomListNode* T1 = A, *T2 = head;
    while (T1 and T2) {
        T2 -> random = u_map[T1 -> random];
        T1 = T1 -> next;
        T2 = T2 -> next;
    }
    return head;
}
