import sys
a, b, c = sys.stdin.readline().split()
a, b, c = int(a), int(b), int(c)

if b >= c:
    print('-1')

else:
    x = int(a/(c-b)) + 1
    print(x)