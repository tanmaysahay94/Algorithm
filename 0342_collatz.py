cache = {}
ans = 0
for i in range(1, 1000001):
    val = i
    curr = 1
    while (val != 1):
        if val % 2:
            val = 3 * val + 1
        else:
            val = val / 2
        if val in cache:
            curr = cache[val] + curr
            break
        else:
            curr = curr + 1
    cache[i] = curr
    if curr > ans:
        ans = curr
        num = i
    print i, cache[i], num, cache[num] 
