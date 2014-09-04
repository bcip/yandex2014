import sys
n = int(sys.stdin.readline().strip())

s = [sys.stdin.readline().strip() for i in xrange(n)]

s.sort()

def upper_bound(all, w):
    l = 0
    r = len(all) - 1
    ans = r + 1
    while l <= r:
        m = (l + r) / 2
        if all[m] > w:
            ans = m
            r = m - 1
        else:
            l = m + 1
    return ans

ans = 0
for w in s:
    d = w
    for i in xrange(len(w)):
        if d[i] != 'a':
            d = d[:i] + 'a' + d[i+1:]
            break
    ans += n - upper_bound(s, d)
    if d != w:
        ans -= 1

print ans