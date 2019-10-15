import math

a = 3
b = 2
c = 3
d = 2

ans = 0

for i in range(1,1000):
    a += d*2
    b += c
    c = a
    d = b

    if int(math.log10(a)) > int(math.log10(b)):
        ans += 1

print(ans)
