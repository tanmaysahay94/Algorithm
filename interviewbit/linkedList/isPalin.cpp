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

ListNode* g(ListNode* A) {
    if (f(A) == 1) {
        return A;
    }
    ListNode* p0 = NULL;
    ListNode* p1 = A;
    ListNode* p2 = A -> next;
    while (p2) {
        p1 -> next = p0;
        p0 = p1;
        p1 = p2;
        p2 = p2 -> next;
    }
    p1 -> next = p0;
    return p1;
}

int Solution::lPalin(ListNode* A) {
    int len = f(A);
    if (len == 1) {
        return 1;
    }
    int checklen = len / 2;
    ListNode* firstEnd = A;
    for (int i = 1; i < checklen; i++) {
        firstEnd = firstEnd -> next;
    }
    ListNode* toRev = firstEnd -> next;
    if (len & 1) {
        toRev = toRev -> next;
    }
    firstEnd -> next = NULL;
    ListNode* rev = g(toRev);
    while (A and rev) {
        if (A -> val != rev -> val) {
            return 0;
        }
        A = A -> next;
        rev = rev -> next;
    }
    return 1;
}
