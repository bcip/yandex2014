def ss2(l):
    res = 2*(10**((l)//2)-1)
    if l&1:
        res += 9*10**(l//2)
    return res+1

(n, k) = raw_input().split(" ")
k=int(k)
if (n[0] == '-'): n = "0"; k-=1
l = len(n);
prefstr = n[:(l+1)//2]
sufstr = n[:-((l+1)//2+1):-1]
pref = long(prefstr)
if k<0:
    if long(sufstr[::-1]) > long(prefstr[::-1]):
        k=k+1
if k>0:
    if long(prefstr[::-1]) > long(sufstr[::-1]):
        k=k-1
ind = pref - 10**((l+1)//2-1) + ss2(len(n)-1) + k
if ind < 0:
    print -1
    exit()
dl = max(1, len(n)-1)
while dl > 1 and ss2(dl-1) > ind: dl -= 1
while ss2(dl) <= ind: dl += 1
ind -= ss2(dl-1)
pref = str(10**((dl-1)/2) + ind)
suf = pref[::-1]
if dl&1:
    suf = suf[1::]
print pref+suf
