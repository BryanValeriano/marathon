from typing import List


def solve(V: List[int]) -> int:
    energy = 0
    last = 0
    ans = 0

    for x in V:
        energy += last - x
        last = x
        ans += max(0, -energy)
        energy = max(0, energy)

    return ans


def main():
    n = int(input())
    V = list(map(int, input().split()))
    print(solve(V))


if __name__ == "__main__":
    main()
