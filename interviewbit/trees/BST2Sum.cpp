class BST{
    public:
        stack<TreeNode*> mys1,mys2;
        TreeNode * cur1, * cur2;

        BST(TreeNode *root) {
            cur1=cur2=root;
        }
        int next(){
            if(cur1!=NULL){
                mys1.push(cur1);
                cur1=cur1->left;
                next();
            }
            else{
                if(not mys1.empty()){
                    cur1=mys1.top();
                    int ans=cur1->val;
                    mys1.pop();
                    cur1=cur1->right;
                    return ans;
                }
            }
        }
        int prev(){
            if(cur2!=NULL){
                mys2.push(cur2);
                cur2=cur2->right;
                prev();
            }
            else{
                if(not mys2.empty()){
                    cur2=mys2.top();
                    int ans=cur2->val;
                    mys2.pop();
                    cur2=cur2->left;
                    return ans;
                }
            }
        }
};

int Solution::t2Sum(TreeNode* A, int B) {
    BST a(A);
    int x1=a.next();
    int x2=a.prev();
    while(x1<x2){
        if(x1+x2==B)return 1;
        if(x1+x2<B)
            x1=a.next();
        else x2=a.prev();
    }
    return 0;
}