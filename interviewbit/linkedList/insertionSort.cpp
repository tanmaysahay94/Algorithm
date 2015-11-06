/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    ListNode *t = A;
    while (t) {
        v.push_back(t -> val);
        t = t -> next;
    }
    sort(v.begin(), v.end());
    ListNode *head, *tail;
    head = tail = NULL;
    for (int i = 0; i < (int) v.size(); i++) {
        if (head == tail and head == NULL) {
            head = tail = new ListNode(v[i]);
        }
        else {
            tail -> next = new ListNode(v[i]);
            tail = tail -> next;
        }
    }
    return head;
}
