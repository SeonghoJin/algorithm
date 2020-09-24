from queue import Queue

n = int(input())
arr = list()

def count(start):
    visit = [None]*n
    q = Queue()
    ret = 0

    q.put((start,0))

    while not q.empty() :
        temp = q.get()
        c = int(temp[0])
        depth = temp[1]
        if(depth == 3) : continue
        if(visit[c] == True) : continue
        visit[c] = True

        ss = arr[c]
        for i in range(n):
            if(ss[i] == 'Y'):
                q.put((i, depth+1))
    
    for i in range(n):
        if(i == start) : continue
        if(visit[i]):
            ret+=1

        
    return ret



for i in range(n):
    s = input()
    arr.append(s)

answer = 0

for i in range(n):
    answer = max(count(i),answer) 

print(answer)