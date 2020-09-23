import sys
name = input()

m = dict()

for c in name:
    m.setdefault(c,0)
    m[c] += 1

e_count = 0
e_char = ''
for key in m.keys():
    if(m[key]%2 != 0) : 
        if(e_count == 1):
            print("I'm Sorry Hansoo")
            sys.exit()
        else :
            e_count = 1
            e_char = key

answer = ""

for key in sorted(m.keys()):
    sz = m[key]
    for i in range(int(sz/2)):
        answer+=key


realanswer = answer + e_char + ''.join(reversed(answer))
print(realanswer)
    