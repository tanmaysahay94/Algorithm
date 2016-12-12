
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <stack>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>
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

struct node {
    int data;
    node *left, *right;
    public:
        node(int d): data(d), left(NULL), right(NULL) {}
};

void inorder(node *root)
{
    if (not root) return;
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
}

void _swap(node *root, int K, int level = 1)
{
    if (not root) return;
    if (level % K == 0) swap(root -> left, root -> right);
    _swap(root -> left, K, level + 1);
    _swap(root -> right, K, level + 1);
}

int main()
{
    node *root = new node(1);
    int n;
    scanf("%d", &n);
    unordered_map<int, node *> U;
    U[1] = root;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l != -1)
        {
            node *_left = new node(l);
            U[i] -> left = _left;
            U[l] = _left;
        }
        if (r != -1)
        {
            node *_right = new node(r);
            U[i] -> right = _right;
            U[r] = _right;
        }
    }
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        int K;
        scanf("%d", &K);
        _swap(root, K);
        inorder(root);
        printf("\n");
    }
    return 0;
}
