int init(int v, int l, int r, vector<int>& tree) {
    if (l == r) {
        return tree[v] = 1;
    }
    int mid = (l + r) / 2;
    return tree[v] = init(2 * v + 1, l, mid, tree) + init(2 * v + 2, mid + 1, r, tree);
}
int find(vector<int>& tree, int v, int l, int r, int val) {
    if (l == r) {
        return l;
    }
    int left = tree[2 * v + 1];
    int right = tree[2 * v + 2];
    int mid = (l + r) / 2;
    if (val < left) {
        return find(tree, 2 * v + 1, l, mid, val);
    }
    else {
        return find(tree, 2 * v + 2, mid + 1, r, val - left);
    }
}
void update(vector<int>& tree, int v, int l, int r, int idx) {
    tree[v]--;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(tree, 2 * v + 1, l, mid, idx);
    }
    else {
        update(tree, 2 * v + 2, mid + 1, r, idx);
    }
}
vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int n = heights.size();
    vector<pair<int, int> > V(n);
    for (int i = 0; i < n; i++) {
        V[i] = make_pair(heights[i], infronts[i]);
    }
    vector<int> ret(n, 0);
    sort(V.begin(), V.end());
    vector<int> tree(2222222, 0);
    init(0, 0, n - 1, tree);
    for (int i = 0; i < n; i++) {
        int loc = find(tree, 0, 0, n - 1, V[i].second);
        ret[loc] = V[i].first;
        update(tree, 0, 0, n - 1, loc);
    }
    return ret;
}