n = 0
m = 0
N = 255
T = 55
dp = [ [-1 for j in range(N)] for i in range(T) ]


def solve(at, sum):
    if(sum == n):
        return 1
    if(sum > n or at >= m):
        return 0
    if(dp[at][sum] != -1):
        return dp[at][sum]

    ans = 0
    i = 0

    while (sum + v[at]*i) <= n:
        ans += solve(at+1,sum+v[at]*i)
        i += 1

    dp[at][sum] = ans
    return dp[at][sum]

n,m = map(int, input().split())
v = list(map(int, input().split()))

print(solve(0,0))

