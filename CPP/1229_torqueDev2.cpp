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

typedef long long LL;
const int maxn = 1e5 + 5;

vector<int> G[maxn];
int V[maxn];

int dfs(int i) {
    if (V[i]) return 0;
    V[i] = 1;
    int ret = 1;
    for (auto &j: G[i]) ret += dfs(j);
    return ret;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++) G[i].clear(), V[i] = 0;
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            G[city_1].push_back(city_2);
            G[city_2].push_back(city_1);
        }
        LL cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (not V[i]) {
                cnt++;
                ans += y * (dfs(i) - 1);
            }
        }
        ans += x * cnt;
        cout << min(ans, (LL) x * n) << endl;
    }
    return 0;
}
