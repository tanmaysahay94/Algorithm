bool isBalanced(TreeNode *root) {
	if (root == NULL) return true;
	return isBalancedWithDepth(root).second;
}

pair<int, bool> isBalancedWithDepth(TreeNode *root) {
	if (root == NULL) return make_pair(0, true);
	pair<int, bool> left = isBalancedWithDepth(root->left);
	pair<int, bool> right = isBalancedWithDepth(root->right);
	int depth = max(right.first, left.first) + 1;
	// The subtree is balanced if right subtree is balanced, left subtree is balanced 
	// and the depth difference is less than 1. 
	bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);
	return make_pair(depth, isbalanced);
}
