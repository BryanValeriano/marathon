def solve(S: str, tot: int) -> int:
    if len(S) == 1:
        return tot

    else:
        sum = 0
        for s in S:
            sum += int(s)
        return solve(str(sum), tot+1)


def main():
    S = input()
    print(solve(S, 0))


if __name__ == "__main__":
    main()
