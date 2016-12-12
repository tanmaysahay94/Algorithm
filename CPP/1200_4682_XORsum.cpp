
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

class trie {
    trie *T[2];
    public:
        trie() {
            T[0] = T[1] = NULL;
        }
        void insert(int val, trie *t) {
            for (int i = 30; i >= 0; i--) {
                int bit = (val >> i) & 1;
                if (not t -> T[bit]) {
                    t -> T[bit] = new trie();
                }
                t = t -> T[bit];
            }
        }
        int xorMax(int val, trie *t) {
            int ans = 0;
            for (int i = 30; i >= 0; i--) {
                int bit = (val >> i) & 1;
                int dig = !bit;
                if (t -> T[dig]) {
                    t = t -> T[dig];
                    ans = ans | (1 << i);
                }
                else {
                    t = t -> T[bit];
                }
            }
            return ans;
        }
};

const int maxn = 1e5 + 5;
vector<int> V(maxn), P(maxn);

int main()
{
    P[0] = 0;
    int __T;
    scanf("%d", &__T);
    for (int T = 1; T <= __T; T++)
    {
        trie *t = new trie();
        t -> insert(P[0], t);
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &V[i]);
            P[i + 1] = P[i] ^ V[i];
            t -> insert(P[i + 1], t);
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, t -> xorMax(P[i], t));
        }
        printf("%d ", ans);
    }
    return 0;
}
