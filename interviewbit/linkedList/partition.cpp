/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	ListNode *ltHead, *ltTail;
	ltHead = ltTail = A;
	ListNode *it = A;
	while (it and it -> val >= B) {
		it = it -> next;
	}
	ltHead = ltTail = it;
	ListNode *geHead, *geTail;
	geHead = geTail = A;
	it = A;
	while (it and it -> val < B) {
		it = it -> next;
	}
	geHead = geTail = it;
	if (not ltHead or not geHead) {
		return A;
	}
	it = A;
	while (it) {
		if (it -> val < B) {
			if (ltHead == ltTail and ltTail == it) {
				it = it -> next;
				continue;
			}
			ltTail -> next = it;
			ltTail = it;
		}
		else {
			if (geHead == geTail and geTail == it) {
				it = it -> next;
				continue;
			}
			geTail -> next = it;
			geTail = it;
		}
		it = it -> next;
	}
	geTail -> next = NULL;
	ltTail -> next = geHead;
	return ltHead;
}
