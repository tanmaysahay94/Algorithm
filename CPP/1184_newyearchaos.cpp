#include <iostream>
#include <vector>
#include <algorithm>
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

class BIT {
    private:
        int n;
        vector<int> T;
    public:
        BIT(int _n) {
            n = _n;
            T.resize(n + 1);
        }
        int get(int v) {
            int ret = 0;
            while (v) {
                ret += T[v];
                v -= (v&(-v));
            }
            return ret;
        }
        void update(int v) {
            while (v < (int) T.size()) {
                T[v]++;
                v += (v&(-v));
            }
        }
};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (auto &u: v)
            scanf("%d", &u);
        BIT bit(n);
        bool possible = true;
        int ans = 0;
        for (int i = n - 1; i >= 0 and possible; i--)
        {
            int val = bit.get(v[i]);
            if (val > 2)
                possible = false;
            ans += val;
            bit.update(v[i]);
        }
        if (not possible) cout << "Too chaotic\n";
        else cout << ans << endl;
    }
    return 0;
}
