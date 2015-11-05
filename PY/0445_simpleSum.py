def fastPow(base, exp, mod):
    ans = 1
    while exp:
        if exp & 1:
            ans = (ans * base) % mod
        base = (base * base) % mod
        exp >>= 1;
    return ans

t = int(raw_input())
while t:
    s = raw_input().split()
    try:
        x = int(s[0])
        m = int(s[1])
        n = int(s[2])
        if x != 1:
            nr = fastPow(x, m + 1, (x - 1) * n) - 1
            dr = x - 1
            nr = (nr / dr) % n
            print nr
        else:
            print (m + 1) % n
    except EOFError:
        break
    t -= 1
