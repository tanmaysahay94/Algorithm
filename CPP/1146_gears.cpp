#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod1 = 1e18 + 3;
const LL mod2 = 1e18 + 9;

LL powMod(LL a, LL b, LL mod = mod1)
{
        LL ret = 1;
        while (b)
        {
                if (b & 1)
                        ret = (ret * a) % mod;
                a = (a * a) % mod;
                b >>= 1;
        }
        return ret;
}

struct pair_hash
{
        inline LL operator() (const pair<LL, LL> &v) const
        {
                return powMod(v.first, v.second);
        }
};

void read(vector<LL>& V)
{
        for (auto &v: V)
                scanf("%lld", &v);
}

int main()
{
        int T;
        scanf("%d", &T);
        for (int __T = 1; __T <= T; __T++)
        {
                int Np, Ne, Nt;
                scanf("%d%d%d", &Np, &Ne, &Nt);
                vector<LL> P(Np), E(Ne), T(Nt);
                read(P);
                read(E);
                read(T);
                LL M;
                scanf("%lld", &M);
                printf("Case #%d:\n", __T);
                while (M--)
                {
                        LL p, q;
                        scanf("%lld%lld", &p, &q);
                        set<pair<LL, LL> > ok;
                        for (int i = 0; i < Np; i++)
                                for (int j = 0; j < Nt; j++)
                                {
                                        LL gcd = __gcd(P[i] * q, T[j] * p);
                                        ok.insert(make_pair((P[i] * q) / gcd, (T[j] * p) / gcd));
                                }
                        bool found = false;
                        for (int i = 0; i < Ne and not found; i++)
                                for (int j = 0; j < Ne and not found; j++)
                                        if (i != j)
                                        {
                                                LL gcd = __gcd(E[i], E[j]);
                                                if (ok.count(make_pair(E[i] / gcd, E[j] / gcd)))
                                                        found = true;
                                        }
                        printf("%s\n", found ? "Yes" : "No");
                }
        }
        return 0;
}
