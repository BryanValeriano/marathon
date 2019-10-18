N = 333
dp = [ [-1 for i in range(N+1) ] for j in range(N+1) ]

def ok(x,y):
    return ((y-x+1) % 2 == 0)

def solve(l,r):
    if(r-l+1 == 2):
        return 1

    if(dp[l][r] != -1):
        return dp[l][r]

    ans = 0

    for i in range(l+1,r):
        if ok(l,i) and ok(i+1,r):
            ans += solve(l,i) * solve(i+1,r)

    dp[l][r] = ans

    return ans

n = int(input());

while(n != -1):
    n += 1
    n = n*2
    ans = 0

    for i in range(2,n):
        if ok(1,i) and ok(i+1,n):
            ans += solve(1,i) * solve(i+1,n)

    print(ans)

    n = int(input())


