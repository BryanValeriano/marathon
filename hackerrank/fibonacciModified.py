import os
import sys
import re
import random
import math

N = 22
dp = [-1 for i in range(N)]

def solve(n):
    if dp[n] != -1:
        return dp[n]

    dp[n] = solve(n-1)*solve(n-1) + solve(n-2)
    return dp[n]


fptr = open(os.environ['OUTPUT_PATH'], 'w')
x = input().split()

t1 = int(x[0])
t2 = int(x[1])
n = int(x[2])
dp[1] = t1
dp[2] = t2
ans = solve(n)
fptr.write(str(ans) + '\n')
fptr.close()

