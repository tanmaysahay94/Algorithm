
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

typedef long long LL;

class trie
{
    private:
        unordered_map<LL, trie *> next;
    public:
        trie() {}
        void insert(LL num, trie *t)
        {
            for (LL denom = 1e9; denom; denom /= 10)
            {
                LL dig = (num / denom) % 10;
                if (t -> next.count(dig) == 0)
                    t -> next[dig] = new trie();
                t = t -> next[dig];
            }
        }
        LL maximize(LL num, trie *t)
        {
            LL ans = 0;
            for (LL denom = 1e9; denom; denom /= 10)
            {
                LL dig = (num / denom) % 10;
                LL mx = -1, argmx = -1;
                for (auto &n: t -> next)
                    if ((n.first + dig) % 10 > mx)
                        mx = (n.first + dig) % 10, argmx = n.first;
                ans = ans * 10 + mx;
                t = t -> next[argmx];
            }
            return ans;
        }
};

LL xsum(LL a, LL b)
{
    if (a < b)
        swap(a, b);
    LL ans = 0;
    while (a and b)
    {
        LL d1 = a % 10;
        LL d2 = b % 10;
        d1 += d2;
        d1 %= 10;
        ans = ans * 10 + d1;
        a /= 10;
        b /= 10;
    }
    while (a)
    {
        ans = ans * 10 + (a % 10);
        a /= 10;
    }
    LL ret = 0;
    while (ans)
    {
        ret = ret * 10 + (ans % 10);
        ans /= 10;
    }
    return ret;
}

void transform(vector<vector<LL> >& ret, vector<LL>& V)
{
    LL n = V.size();
    LL lim = 1 << n;
    ret = vector<vector<LL> > (n + 1);
    for (LL mask = 0; mask < lim; mask++)
    {
        LL val = 0;
        for (LL bit = 0; bit < n; bit++)
            if ((mask >> bit) & 1)
                val = xsum(val, V[bit]);
        ret[__builtin_popcount(mask)].push_back(val);
    }
}

int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    vector<LL> O, E;
    for (LL i = 0; i < n; i++)
    {
        LL val;
        scanf("%lld", &val);
        if (i & 1) O.push_back(val);
        else E.push_back(val);
    }
    vector<vector<LL> > L, R;
    transform(L, O);
    transform(R, E);
    LL ans = -1;
    for (int i = 0; i < (int) L.size(); i++)
        for (int j = 0; j < (int) R.size(); j++)
        {
            if (i + j != k)
                continue;
            trie *t = new trie();
            for (auto &num: L[i])
                t -> insert(num, t);
            LL mx = -1;
            for (auto &num: R[j])
                mx = max(mx, t -> maximize(num, t));
            ans = max(ans, mx);
        }
    printf("%lld\n", ans);
    return 0;
}
