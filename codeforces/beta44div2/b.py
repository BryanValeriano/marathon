def norm(S: list) -> list:
    tmp = ''
    if S[1] == '<':
        tmp = S[0]
        S[0] = S[2]
        S[2] = tmp
    return S


def buildGraph() -> dict:
    revDeg = {}

    for i in range(3):
        S = list(input())
        S = norm(S)

        if S[0] not in revDeg:
            revDeg[S[0]] = 0

        revDeg[S[0]] += 1

        if len(revDeg) == 3:
            print("Impossible")
            exit()

    return revDeg


def solve(revDeg: dict):
    S = ['A', 'B', 'C']
    ans = ['x', 'x', 'x']

    for s in S:
        if s not in revDeg:
            revDeg[s] = 0
        ans[revDeg[s]] = s

    print("".join(ans))


def main():
    revDeg = buildGraph()
    solve(revDeg)


if __name__ == "__main__":
    main()
