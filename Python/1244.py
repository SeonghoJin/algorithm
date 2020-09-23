import math
switchCount = int(input())
switchState = list(map(int, input().split(' ')))
studentCount = int(input())

def changeSwitch(a, num):
    if(a == 1):
        for i in range(switchCount):
            if (i+1) % num == 0 : switchState[i] = 1 - switchState[i]
    else :
        num -= 1
        for i in range(switchCount//2):
            left = num - i
            right = num + i
            if(left < 0 or right >= switchCount):
                break
            if(switchState[left] != switchState[right]):
                break
            else:
                if(left == num):
                    switchState[num] = 1- switchState[num]
                switchState[left] = 1- switchState[left]
                switchState[right] = 1- switchState[right]

for i in range(studentCount):
    x, num = list(map(int, input().split(' ')))
    changeSwitch(x, num)

k = switchCount / 20
k = math.ceil(k)
start = 0
end = 20
for len in range(k):
    li = switchState[start:end]
    li = map(str,li)
    print(' '.join(li))
    start += 20
    end += 20
    