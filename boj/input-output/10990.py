n = int(input())

for i in range(n):
    print(' ' * (n-i-1), end='')
    print('*', end='')

    if i == 0:
        print()
        continue

    print(' ' * (i*2-1), end='')
    print('*')
