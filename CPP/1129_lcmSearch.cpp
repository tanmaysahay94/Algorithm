#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n;
const LL maxlim = 31622777;
vector<int> sieve(maxlim + 1, 1);
vector<LL> primes;

LL fastPowMod(LL a, LL b, LL n)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return ret;
}

bool miller(LL n, int iter)
{
    if (n < 2) return false;
    if (n % 2 == 0) return false;
    LL d = n - 1;
    while (d % 2 == 0) d >>= 1;
    for (int i = 0; i < iter; i++)
    {
        LL a = rand() % (n - 1) + 1, temp = d;
        LL mod = fastPowMod(a, temp, n);
        while (temp != n - 1 and mod != 1 and mod != n - 1)
        {
            mod = fastPowMod(mod, mod, n);
            temp <<= 1;
        }
        if (mod != n - 1 and temp % 2 == 0)
            return false;
    }
    return true;
}

bool isPrime(LL n)
{
    return miller(n, 30);
}

void init()
{
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i < (int) sieve.size(); i++)
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < (int) sieve.size(); j += i)
                sieve[j] = 0;
        }
}

int main()
{
    scanf("%lld", &n);
    if (n < 7)
    {
        if (n == 1) printf("1\n");
        else if (n == 2) printf("2\n");
        else if (n == 3) printf("2\n");
        else if (n == 4) printf("3\n");
        else if (n == 5) printf("3\n");
        else printf("4\n");
        return 0;
    }
    init();
    LL lowLim = n / 2;
    unordered_set<LL> primePowers;
    for (auto p: primes)
    {
        if (p * p > n) break;
        int mxp = log2((double) n) / log2((double) p);
        LL val = 1;
        for (int i = 1; i <= mxp; i++)
        {
            val *= p;
            primePowers.insert(val);
        }
    }
    bool found = false;
    LL ans = n / 2;
    while (not found)
    {
        ans++;
        if (primePowers.count(ans)) break;
        else if (isPrime(ans)) break;
    }
    printf("%lld\n", ans);
    return 0;
}
