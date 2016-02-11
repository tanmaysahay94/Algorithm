#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

typedef struct node {
	int val;
	node *left, *right;
	node(int _val): val(_val), left(NULL), right(NULL) {}
} node;

void inorder(node* t)
{
	if (!t) return;
	inorder(t -> left);
	cout << t -> val << ' ';
	inorder(t -> right);
}

node *generate(vector<int>& pre, vector<int>& post, int& preIdx, int low, int high, int sz)
{
	if (low > high or preIdx >= sz) return NULL;
	node *root = new node(pre[preIdx++]);
	if (low == high) return root;
	int idx = 0;
	for (idx = low; idx <= high; idx++)
		if (post[idx] == pre[preIdx])
			break;
	if (idx <= high)
	{
		root -> left = generate(pre, post, preIdx, low, idx, sz);
		root -> right = generate(pre, post, preIdx, idx + 1, high, sz);
	}
	return root;
}

node *prePost(vector<int>& pre, vector<int>& post)
{
	int n = pre.size();
	int preIdx = 0;
	return generate(pre, post, preIdx, 0, n - 1, n);
}

int main()
{
	int n;
	cin >> n;
	vector<int> pre(n), post(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	node *root = prePost(pre, post);
	inorder(root);
	cout << endl;
	return 0;
}
