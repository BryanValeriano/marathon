from typing import List

class Solution:
    def simplifiedEuclidDist(self,point: List[int]) -> int:
        return sum(coord * coord for coord in point)

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=self.simplifiedEuclidDist)
        return points[:k]

def main():
    print(Solution().kClosest([[1,3],[-2,2]],1))

if __name__ == "__main__":
    main()
