a,b = input().split(' ')
len_a = len(a)
len_b = len(b)

answer = 0
flag = True
if(len_a != len_b):
    print(0)
else:
    for i in range(len_a):
        if(a[i] == '8' and b[i] == '8' and flag):
            answer+=1
        elif(a[i] != b[i]):flag = False
    print(answer)




