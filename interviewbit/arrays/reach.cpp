// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    if (X.size() == 1) {
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i < (int) X.size(); i++) {
        pair<int, int> to = make_pair(X[i], Y[i]);
        pair<int, int> from = make_pair(X[i - 1], Y[i - 1]);
        if (to.first < from.first) {
            swap(to, from);
        }
        if (to.second < from.second) {
            swap(to.second, from.second);
        }
        int r1 = abs(to.first - from.first) + abs(to.second - from.second);
        int r2 = 0;
        if (abs(to.first - from.first) < abs(to.second - from.second)) {
            r2 = abs(to.second - from.second);
        }
        else {
            r2 = abs(to.first - from.first);
        }
        ans += min(r1, r2);
    }
    return ans;
}
