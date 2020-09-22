m = dict()

li = list([10,20,30,40])


m.setdefault(10,0)
m[10]+=1
print(m[10])
m.setdefault(10,0)
m[10]+=1
print(m[10])