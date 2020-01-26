import sys

def draw(x,y):
    while x != 0:
        if (x%3) == 1 and (y%3) == 1:
            sys.stdout.write(' ')
            return
        x = x // 3
        y = y // 3
    
    sys.stdout.write('*')


n = int(input())
for i in range(n):
    for j in range(n):
        draw(j,i)
    sys.stdout.write('\n')
