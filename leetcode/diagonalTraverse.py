from typing import List, Tuple

#  diagonal superior direita  {-1,1}
#  direita                    {0, 1} baixo   {1,0}
#  diagonal inferior esquerda {1,-1}
#  baixo                      {1, 0} direita {0,1}

class Solution:
    def getNextPos(self, posAt: Tuple, mov: Tuple) -> Tuple:
        return (posAt[0]+mov[0], posAt[1]+mov[1])

    def isInside(self, x: int, y: int, pos: Tuple) -> bool:
        xx = pos[0]
        yy = pos[1]
        return xx >= 0 and xx <= x and yy >= 0 and yy <= y

    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        n = len(mat)
        m = len(mat[0])
        movWhileTrue = [(-1,1), (1,-1)]
        movOneTime = [(0,1), (1,0)]

        visited = 0
        needToVisit = n*m
        posAt = (0,0)
        posMovWhileTrue = 0
        order = []

        while True:
            visited += 1
            order.append(mat[posAt[0]][posAt[1]])
            if visited == needToVisit:
                break
            nextPos = self.getNextPos(posAt, movWhileTrue[posMovWhileTrue])
            attempt = 0
            while self.isInside(n-1,m-1,nextPos) == False:
                nextPos = self.getNextPos(posAt, movOneTime[(posMovWhileTrue + attempt)%2])
                attempt += 1
            
            posAt = nextPos
            if attempt > 0:
                posMovWhileTrue = (posMovWhileTrue + 1) % 2

        return order


def main():
    n,m = list(map(int, input().split()))
    mat = [[] for _ in range(n)]
    for i in range(n):
        mat[i] = list(map(int, input().split()))

    print(mat)
    print(Solution().findDiagonalOrder(mat))

if __name__ == "__main__":
    main()
 
