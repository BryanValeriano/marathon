n, h = list(map(int, input().split()))
V = list(map(int, input().split()))
ans = n

for x in V:
    if x > h:
        ans += 1
    
print(ans)
