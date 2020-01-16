month = [0,31,28,31,30,31,30,31,31,30,31,30]

mon, day = map(int, input().split())
day_sum=0

for i in range(mon):
    day_sum = day_sum + month[i]

day_sum = day_sum + day
result = day_sum % 7

if result == 0:
    print("SUN")
elif result == 1:
    print("MON")
elif result == 2:
    print("TUE")
elif result == 3:
    print("WED")
elif result == 4:
    print("THU")
elif result == 5:
    print("FRI")
else:
    print("SAT")
