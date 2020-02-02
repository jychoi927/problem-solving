test_case = int(input())

d = []
d.append(0)
d.append(1)
d.append(2)
d.append(4)

for i in range(4,11):
    d.append(d[i-1] + d[i-2] + d[i-3])

for _ in range(test_case):
    n = int(input())
    print(d[n])

