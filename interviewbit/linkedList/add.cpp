/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
 int len(listnode* l) {
     int ret = 0;
     while (l) {
         ret++;
         l = l -> next;
     }
     return ret;
 }
 listnode* last(listnode* A) {
     listnode* curr = A;
     listnode* nxt = curr -> next;
     while (nxt) {
         curr = nxt;
         nxt = nxt -> next;
     }
     return curr;
 }
 listnode* helper(listnode* A, listnode* B) {
     listnode *ret = A;
     listnode* it = A;
        listnode* alast = last(A);
        int carry = 0;
        while (B) {
            int sum = it->val + B->val + carry;
            it->val = sum % 10;
            carry = sum / 10;
            B = B -> next;
            it = it -> next;
        }
        while (it) {
            int sum = it->val + carry;
            it->val = sum % 10;
            carry = sum / 10;
            it = it -> next;
        }
        if (carry) {
            listnode* foo = listnode_new(carry);
            alast -> next = foo;
        }
    return ret;
 }
 
listnode* addTwoNumbers(listnode* A, listnode* B) {
    int la = len(A);
    int lb = len(B);
    listnode* ret;
    if (la > lb) {
        return helper(A, B);
    }
    return helper(B, A);
}
