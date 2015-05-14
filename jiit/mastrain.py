def f(n):
    return (n * (n + 1) * (2*n + 1))/3
def g(n):
    return f(n) + n*(n+1)
mod = 1000000007
t = int(raw_input())
while t:
    t -= 1
    a = raw_input()
    a = a.split()
    m = int(a[0])
    n = int(a[1])
    if m > n:
        m, n = n, m
    ans = f(m)*(n-m+1)
    if n == m:
        print int(ans)
        continue
    ans -= (n-m)*g(m-1)
    ans %= mod
    if ans < 0:
        ans += mod
    print int(ans)
