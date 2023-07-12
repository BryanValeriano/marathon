def main():
    S = "ROYGBIV"
    ans = ""
    n = int(input())

    for i in range(n):

        if i < len(S):
            ans += S[i]
        else:
            ans += ans[i-4]

    print(ans)


if __name__ == "__main__":
    main()
