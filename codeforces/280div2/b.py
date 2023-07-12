def solve(V: list, t: int):
    ans = max(V[0], t - V[len(V)-1])
    last = V[0]
    for v in V:
        ans = max(ans, (v-last)/2)
        last = v

    print(ans)


def main():
    n, t = list(map(int, input().split()))
    V = list(map(int, input().split()))
    V.sort()
    solve(V, t)


if __name__ == "__main__":
    main()
