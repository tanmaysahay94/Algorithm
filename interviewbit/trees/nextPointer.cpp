TreeLinkNode* nextInLevel(TreeLinkNode* T) {
    TreeLinkNode* tmp = T -> next;
    while (tmp) {
        if (tmp -> left) {
            return tmp -> left;
        }
        if (tmp -> right) {
            return tmp -> right;
        }
        tmp = tmp -> next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* tmp;
    if (not A) {
        return;
    }
    A -> next = NULL;
    while (A) {
        TreeLinkNode* lvlTrav = A;
        while (lvlTrav) {
            if (lvlTrav -> left) {
                if (lvlTrav -> right) {
                    lvlTrav -> left -> next = lvlTrav -> right;
                }
                else {
                    lvlTrav -> left -> next = nextInLevel(lvlTrav);
                }
            }
            if (lvlTrav -> right) {
                lvlTrav -> right -> next = nextInLevel(lvlTrav);
            }
            lvlTrav = lvlTrav -> next;
        }
        if (A -> left) {
            A = A -> left;
        }
        else if (A -> right) {
            A = A -> right;
        }
        else {
            A = nextInLevel(A);
        }
    }
}
