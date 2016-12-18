#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class DSU {
    public:
        vector<int> par, sz;
        DSU(int n) {
            par = vector<int> (n);
            sz = vector<int> (n, 1);
            for (int i = 0; i < n; i++) par[i] = i;
        }
        int rep(int i) {return par[i] == i ? i : par[i] = rep(par[i]);}
        void merge(int i, int j) {
            i = rep(i);
            j = rep(j);
            if (i == j) return;
            if (sz[i] < sz[j]) swap(i, j);
            par[j] = i;
            sz[i] += sz[j];
            sz[j] = 0;
        }
};

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;
        DSU dsu(n);
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            city_1--;
            city_2--;
            dsu.merge(city_1, city_2);
        }
        long long cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) if (dsu.sz[i] != 0) cnt++, ans += y * (dsu.sz[i] - 1);
        ans += x * cnt;
        cout << min(ans, (long long) x * n) << endl;
    }
    return 0;
}
