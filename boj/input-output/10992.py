n = int(input())

for i in range(n-1):
    print(' ' * (n-i-1), end='')
    print('*', end='')
    if i==0:
        print()
        continue
    print(' ' * (i*2-1), end='')
    print('*')

print('*'*(n*2-1))
