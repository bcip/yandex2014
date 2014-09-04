import sys
import random
import string
import math

random.seed(1231241)
ID = 0

def write(s):    
    global ID
    ID += 1
    print >> sys.stderr, 'Test #%d' % ID
    assert 1 <= len(s) <= 10**6
    assert 1 <= sum(map(len, s)) <= 10**6
    f = open("%d" % ID, "w")
    print >> f, len(s)
    for w in s:
        print >> f, w
    f.close()

def hash(d, a, b):
    if d == 1:
        return a + b, b + a
    else:
        w, r = hash(d-1, a, b)
        return w + r, r + w
    
write(['a', 'b', 'c'])
write(['aab','aba'])
write(['aa','aaa'])
write(['aaaa','aa','aba','aaab'])
write(['aaaa','aaab','aaba','abaa'])

for l in xrange(1, 11):
    write([''.join([random.choice(string.lowercase) for i in xrange(l)]) for j in xrange(10**6 / l)])

write([990*'a' + ''.join([random.choice(string.lowercase) for i in xrange(random.randint(1,10))]) for j in xrange(10**3)])

for t in xrange(10):
    lines = []
    total_length = 0
    max_len = random.randint(1, 10)
    while total_length + max_len <= 10**6:
        l = random.randint(1, max_len)
        w = ''.join([random.choice(string.lowercase) for i in xrange(l)])
        total_length += l
        lines.append(w)
    write(lines)

for t in xrange(10):
    lines = []
    total_length = 0
    max_len = random.randint(1, 10)
    num_sym = random.randint(1, len(string.lowercase))
    while total_length + max_len <= 10**6:
        l = random.randint(1, max_len)
        w = ''.join([random.choice(string.lowercase[:num_sym]) for i in xrange(l)])
        total_length += l
        lines.append(w)
    write(lines)

for t in xrange(5):
    A, B = hash(10 + t, random.choice(string.lowercase), random.choice(string.lowercase))
    max_len = random.randint(1, 10)
    num_sym = random.randint(1, len(string.lowercase))
    lines = []
    total_length = 0
    while total_length + max_len * 4 + 2 * len(A) <= 10**6:
        l = random.randint(1, max_len)
        p = ''.join([random.choice(string.lowercase[:num_sym]) for i in xrange(l)])
        l = random.randint(1, max_len)
        s = ''.join([random.choice(string.lowercase[:num_sym]) for i in xrange(l)])
        total_length += len(p) * 2 + len(s) * 2 + len(A) * 2
        lines.append(p + A + s)
        lines.append(p + B + s)
    random.shuffle(lines)
    write(lines)

for t in xrange(5):
    A, B = hash(10 + t, random.choice(string.lowercase), random.choice(string.lowercase))
    max_len = random.randint(len(A), len(A) + 100)
    num_sym = random.randint(1, len(string.lowercase))
    lines = []
    total_length = 0
    while total_length + max_len * 2 + 2 * len(A) <= 10**6:
        l = random.randint(1, max_len)
        p = ''
        l = random.randint(1, max_len)
        s = ''.join([random.choice(string.lowercase[:num_sym]) for i in xrange(l)])
        total_length += len(p) * 2 + len(s) * 2 + len(A) * 2
        lines.append(p + A + s)
        lines.append(p + B + s)
    random.shuffle(lines)
    write(lines)

# two tests with only letter 'a'
# two tests with only letter 'b'
for t in xrange(4):
    lines = []
    total_length = 0
    max_len = random.randint(1, 1000)
    while total_length + max_len <= 10**6:
        l = random.randint(1, max_len)
        w = ''.join([random.choice(string.lowercase[t/2:t/2+1]) for i in xrange(l)])
        total_length += l
        lines.append(w)
    write(lines)

write(['a'])
write(['a'] * 1000000)
write(['a', 'ab'])
write(['aa', 'ab'])
write(['aaa', 'ab'])