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

const int maxn = 1e5 + 1;

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

vector<pair<int, int> > printThing[maxn];

void prettyPrintGenerate(node* t, int level, int& spaces)
{
	if (!t) return;
	prettyPrintGenerate(t -> left, level + 1, spaces);
	printThing[level].push_back(make_pair(t -> val, spaces++));
	prettyPrintGenerate(t -> right, level + 1, spaces);
}

int main()
{
	int PRETTY_PRINT = 1;
	int n;
	cin >> n;
	vector<int> pre(n), post(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	node *root = prePost(pre, post);
	if (!PRETTY_PRINT)
	{
		inorder(root);
		cout << endl;
	}
	else
	{
		string spaceChar = "  ";
		int spcCnt = 0;
		prettyPrintGenerate(root, 0, spcCnt);
		for (int i = 0; i < maxn and printThing[i].size(); i++, cout << endl)
		{
			for (int j = 0; j < printThing[i][0].second; j++) cout << spaceChar;
			cout << printThing[i][0].first;
			for (int j = 1; j < (int) printThing[i].size(); j++)
			{
				int spacesToPrint = printThing[i][j].second - printThing[i][j - 1].second - 1;
				for (int k = 0; k < spacesToPrint; k++) cout << spaceChar;
				cout << printThing[i][j].first;
			}
		}
	}
	return 0;
}
