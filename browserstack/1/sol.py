import sys

count = dict()
lines = []

for line in sys.stdin:
    line = line.rstrip('\n')
    lines.append(line)

def clean(w):
    if len(w) <= 2:
        return w
    if w[0] == '"':
        w = w[1:]
    if w[-1] == '"':
        w = w[:-1]
    return w

for i in xrange(len(lines) - 5):
    lines[i] = lines[i].split()
    for word in lines[i]:
        word = clean(word)
        if word in count:
            count[word] += 1
        else:
            count[word] = 1

queryStrings = lines[-5:]

for query in queryStrings:
    query = clean(query)
    if query in count:
        print count[query]
    else:
        if len(query) > 1:
            ans = 100000000000000000000000000
            words = query.split()
            for word in words:
                if word in count:
                    ans = min(ans, count[word])
                else:
                    ans = 0
            print ans
        else:
            print 0
