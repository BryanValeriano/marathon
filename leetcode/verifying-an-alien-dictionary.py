from typing import List

class Solution:
    def converLetterToNumber(self, letter: str) -> int:
        return ord(letter) - ord('a')

    def isWordAGreaterThanWordB(self, a: str, b: str, letterOrder: List[int]) -> bool:
        for i in range(min(len(a),len(b))):
            letterOrderA = letterOrder[self.converLetterToNumber(a[i])]
            letterOrderB = letterOrder[self.converLetterToNumber(b[i])]
            if(letterOrderA > letterOrderB):
                return True
            if(letterOrderA < letterOrderB):
                return False 

        return len(a) > len(b) 

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        letterOrder = [0 for _ in range(len(order))]
        for i in range(len(order)):
            letterOrder[self.converLetterToNumber(order[i])] = i

        last = words[0]
        for word in words:
            if(self.isWordAGreaterThanWordB(last,word, letterOrder)):
                return False
            last = word

        return True 

def main():
    words = ["hello","leetcode"]
    order = "hlabcdefgijkmnopqrstuvwxyz"
    print(Solution().isAlienSorted(words,order))
    words = ["word","world","row"]
    order = "worldabcefghijkmnpqstuvxyz"
    print(Solution().isAlienSorted(words,order))

if __name__ == "__main__":
    main()
