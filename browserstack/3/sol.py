import sys
import xml.etree.ElementTree as ET

reached = False

text = ""
query = ""

def getTag(name):
    ret = ""
    for i in name:
        if i == '[':
            break
        else:
            ret += i
    return ret

def getIdx(name):
    idx = 0
    i = 0
    while name[i] != '[':
        i += 1
    i += 1
    while name[i] != ']':
        char = name[i]
        asciiVal = ord(char)
        num = asciiVal - 48
        idx = 10 * idx + num
        i += 1
    return idx

for line in sys.stdin:
    if not reached:
        if line == "EOF\n":
            reached = True
        else:
            text += line
    else:
        query = line.rstrip('\n')

query = query.split('/')[2:]

root = ET.fromstring(text)

for node in query:
    if node[-1] == ']':
        idx, tagName = getIdx(node), getTag(node)
        i = 0
        for child in root:
            if child.tag == tagName:
                break
            i += 1
        root = root[i + idx]
    else:
        i = 0
        for child in root:
            if child.tag == node:
                break
            i += 1
        root = root[i]

print root.text
