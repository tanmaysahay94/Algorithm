#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

bool solve(vector<LL> A, bool rev)
{
    if (rev)
        reverse(A.begin(), A.end());
    LL n = A.size();
    vector<LL> pre(A), post(A);
    for (int i = 1, j = n - 2; i < n; i++, j--)
    {
        pre[i] += pre[i - 1];
        post[j] += post[j + 1];
    }
    for (int i = 0; i < n; i++)
        cout << i << " " << pre[i]<< " " << post[i] << endl;
    unordered_multiset<LL> UM;
    for (auto &a: A)
        UM.insert(a);
    for (int i = 0; i < n - 1; i++)
    {
        UM.erase(UM.find(A[i]));
        LL s1 = pre[i];
        LL s2 = post[i + 1];
        LL diff = s2 - s1;
        if (diff == 0) return true;
        if (diff < 0 or diff & 1) continue;
        diff /= 2;
        if (UM.count(diff))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL n;
    cin >> n;
    vector<LL> pre(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    if (n == 1)
    {
        cout << "NO\n";
        return 0;
    }
    if (n == 2) 
    {
        if (pre[0] == pre[1])
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }
    if (solve(pre, 0) or solve(pre, 1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
