import sys;
m = dict()
n,v,p = map(int, input().split(' '))
if(n == 0):
    print(1)
    sys.exit()
arr = map(int, input().split(' '))

for value in arr :
    m.setdefault(value,0)
    m[value] += 1

m.setdefault(v,0)
m[v] += 1
s = 0

for key in sorted(m.keys(),reverse=True) :
    s += m[key]
    if(key == v):
        break

if s <= p :
    print (s - m[v] + 1)
else :
    print(-1)