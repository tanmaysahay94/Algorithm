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
    for j in xrange(len(lines[i]) - 1):
        word = lines[i][j] + ' ' +  lines[i][j + 1]
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
        print 0
