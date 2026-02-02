from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total = 1
        prefix = [total := total * num for num in nums] 
        total = 1
        suffix = [total := total * num for num in nums[::-1]][::-1]
        ans = [0 for _ in nums]

        for i in range(len(nums)):
            left = 1 if i == 0 else prefix[i-1]
            right = 1 if i == len(nums)-1 else suffix[i+1]
            ans[i] = left * right

        return ans

def main():
    print(Solution().productExceptSelf([1,2,3,4]))
    print(Solution().productExceptSelf([-1,1,0,-3,3]))

if __name__ == "__main__":
    main()
