n = int(input())
num = list(map(int, input().split()))
dp = [0 for i in range(n)]
for i in range(n):
    dp[i] = num[i]
    for j in range(i):
        if num[i] > num[j]:
            dp[i] = max(dp[i], dp[j] + num[i])

print(max(dp))
