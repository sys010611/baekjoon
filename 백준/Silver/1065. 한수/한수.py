N = int(input())
if N < 100:
    count = N
else:
    count = 99
    for i in range(100, N+1):
        splitNum = list(str(i))
        if int(splitNum[2])-int(splitNum[1]) == int(splitNum[1])-int(splitNum[0]):
            count += 1

print(count)