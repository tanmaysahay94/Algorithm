def power(a, b):
    out = 1
    while(b>0):
        if(b&1):
            out = out * a
        a = a * a
        b = b >> 1
    return out
print "Number:",
m = input()
print "Power:",
n = input()
print power(m, n)
