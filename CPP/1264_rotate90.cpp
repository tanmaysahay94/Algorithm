
#include "bits/stdc++.h"
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

void show(vector<vector<int>>& V) {
    int n = V.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << V[i][j] << " ";
        cout << endl;
    }
}

void rotate(vector<vector<int>>& A) {
    int iters = A.size() / 2;

    for (int i = 0, limit = A.size() - 1; i < iters; ++i, --limit) {
        for (int j = i; j < limit; ++j) {
            int i_conv = A.size() - i - 1;
            int j_conv = A.size() - j - 1;

            swap(A[i][j], A[j][i_conv]);
            swap(A[i][j], A[i_conv][j_conv]);
            swap(A[i][j], A[j_conv][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> V(n, vector<int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> V[i][j];

    rotate(V);
    show(V);
    return 0;
}
