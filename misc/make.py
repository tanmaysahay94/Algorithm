import random

print 100
for i in range(100):
    n = 5
    m = random.randint(1, 1000000000)
    q = random.randint(1, 10000)
    print n, m, q
    while q:
        print random.randint(2, n - 1)
        q -= 1
