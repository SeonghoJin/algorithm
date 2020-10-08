N, M= input().split(' ')
N = int(N)
M = int(M)
arr = [None]*N

for i in range(N) :
    arr[i] = input()


s = [0]*M

for i in range(M):
    for j in range(N):
        if(arr[j][i] == '1'):
            s[i] += 1


k = int(input())


for i in range(M):
    if(k == 0) : break
    if(s[i] > N - s[i]) : continue
    else:
        s[i] = N - s[i] 
        k-=1


if(k > 0 and k & 1) : 
    mm = 51
    t = 0

    for i in range(M):
        t = i
        mm = min(mm, abs(s[i] - N + s[i]))
    
    arr[i] = N - arr[i]
    
answer = 0       
for i in range(M):
    answer = max(s[i],answer)

   

print(answer)