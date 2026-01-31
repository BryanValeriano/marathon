class Solution:
    def removeUnclosed(self, s: str, positiveChar: str, negativeChar: str) -> str:
        t = ""
        balance = 0
        for char in s:
            if(char == positiveChar):
                balance += 1
            elif(char == negativeChar):
                balance -= 1
            if(balance < 0):
                balance = 0
                continue
            t += char
        return t

    def minRemoveToMakeValid(self, s: str) -> str:
        s = self.removeUnclosed(s, "(", ")")
        s = s[::-1]
        s = self.removeUnclosed(s, ")", "(")
        s = s[::-1]
        return s

def main():
    print(Solution().minRemoveToMakeValid("lee(t(c)o)de)"))

if __name__ == "__main__":
    main()


