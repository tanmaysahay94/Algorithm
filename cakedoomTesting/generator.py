import random

test = 100000

print test

list = ['?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

for i in range(test):
    k = random.randint(1, 9)
    print k
    tmp = list[:k + 1]
    size = random.randint(1, 100)
    string = ""
    for j in range(size):
        string += random.choice(tmp)
    print string
