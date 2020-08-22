n, k = map(int, input().split())
a = list(map(float, input().split()))

a += a
acc = [0]
for x in a:
    acc.append(acc[-1] + x)

a = [[1 for _ in range(i + 1)] for i in range(n + 1)]
for i in range(2, n + 1):
    for j in range(1, i):
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j]

ans = []
for i in range(n):
    if k == 1:
        ans.append(100 / n)
        continue
    x = 0
    for j in range(n - k + 1):
        x += (acc[n + i + 1] - acc[n + i - j]) * a[n - 2 - j][k - 2]
    x /= a[n][k]
    ans.append(x)

for x in ans:
    print(x, end=" ")
print()