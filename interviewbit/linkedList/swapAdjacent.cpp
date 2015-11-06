/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int f(ListNode *A) {
    int ret = 0;
    while (A) {
        ret++;
        A = A -> next;
    }
    return ret;
}
ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = f(A);
    if (len == 1) {
        return A;
    }
	if (len == 2) {
		ListNode *ret = A -> next;
		ret -> next = A;
		A -> next = NULL;
		return ret;
	}
	ListNode *dummy = new ListNode(0);
	dummy -> next = A;
	ListNode *prev = dummy;
    ListNode *tmp1 = A;
    ListNode *tmp2 = A -> next;
    while (prev and tmp1 and tmp2) {
		prev -> next = tmp2;
        ListNode *tmp3 = tmp2 -> next;
        tmp2 -> next = tmp1;
        tmp1 -> next = tmp3;
		prev = tmp1;
        tmp1 = tmp3;
        if (tmp3 and tmp3 -> next) {
            tmp2 = tmp3 -> next;
        }
        else {
            tmp2 = NULL;
        }
    }
    return dummy -> next;
}
