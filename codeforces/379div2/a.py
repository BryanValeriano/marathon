def solve(S: str) -> tuple[int, int]:
    anton = 0
    danik = 0
    for s in S:
        if s == 'A':
            anton += 1
        else:
            danik += 1
    return anton, danik


def printAnswer(anton: int, danik: int) -> None:
    if anton > danik:
        print("Anton")
    elif danik > anton:
        print("Danik")
    else:
        print("Friendship")


def main():
    n = int(input())
    S = input()
    anton, danik = solve(S)
    printAnswer(anton, danik)


if __name__ == "__main__":
    main()
