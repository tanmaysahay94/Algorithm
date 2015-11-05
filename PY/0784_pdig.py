def pow2sum(exp):
    pow = list(str(2**exp))
    return sum([int(i) for i in pow])
t = int(raw_input())
for i in range(t):
    n = int(raw_input())
    print pow2sum(n)
