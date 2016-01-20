import sys
import re

count = dict()
lines = []

def countnonoverlappingrematches(pattern, thestring):
      return re.subn(pattern, '', thestring)[1]

text = ""

for line in sys.stdin:
    lines.append(line)

for i in xrange(len(lines) - 5):
    text += lines[i]

queries = lines[-5:]

for query in queries:
    queryA = query.rstrip('\n') + ' '
    queryB = '"' + query.rstrip('\n') + '"'
    queryC = ' ' + query.rstrip('\n')
    ans = text.count(queryA)
    ans = max(ans, text.count(queryB))
    print max(ans, text.count(queryC))

'''
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
'''
