from typing import List

class Solution:
    def getCharCost(self, c: str) -> int:
        if(c == "("): return 1
        if(c == ")"): return -1
        return 0

    def getMinimumRemove(self, s: str, at: int, balance: int, memo: List[List[int]]) -> int:
        if(balance < 0):
            return 100
        if(at >= len(s)):
            return 0 if balance == 0 else 100
        if(memo[at][balance] != -1):
            return memo[at][balance]
        
        #keep char
        charCost = self.getCharCost(s[at])
        keep = self.getMinimumRemove(s,at+1,balance+charCost,memo)
        #skip char
        skip = self.getMinimumRemove(s,at+1,balance,memo) + 1

        memo[at][balance] = min(keep,skip)
        return memo[at][balance]

    def impossibleState(self,at: int, balance: int, removed: int, length: int, k: int) -> bool:
        # never shuold reach negative balance
        if(balance < 0):
            return True
        # not possible to reach balance 0
        if(balance > (length - at)):
            return True
        # we removed more than we should have
        if(removed > k):
            return True
        # we need to remove more than we have
        if((length - at) < (k-removed)):
            return True

        return False
        

    def chooseK(self, s: str, at: int, balance: int, removed: int, k: int, currentState: List[str], possibleAnswers: List[str]) -> None:
        if(self.impossibleState(at,balance,removed,len(s),k)):
            return
        if(at == len(s)):
            if(balance == 0 and removed == k):
                possibleAnswers.append("".join(currentState))
            return

        #keep char
        charCost = self.getCharCost(s[at])
        currentState += s[at]
        self.chooseK(s,at+1,balance+charCost,removed,k,currentState, possibleAnswers)
        currentState.pop()

        #remove char
        self.chooseK(s,at+1,balance,removed+1,k,currentState, possibleAnswers)
        
    def removeInvalidParentheses(self, s: str) -> List[str]:
        memo = [[-1 for _ in range(27)] for _ in range(27)]
        minimumRemove = self.getMinimumRemove(s,0,0,memo) 
        possibleAnswers = []
        self.chooseK(s,0,0,0,minimumRemove,[], possibleAnswers)
        return list(dict.fromkeys(possibleAnswers))
       
def main():
    print(Solution().removeInvalidParentheses("()())()"))

if __name__ == "__main__":
    main()
