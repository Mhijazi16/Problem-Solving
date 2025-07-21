import sys
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start = 0 
        end = 0 
        ans = sys.maxsize 
        sum = 0

        while end < len(nums): 
            sum += nums[end]
            if sum >= target: 
                ans = min(ans, end - start)
                start += 1
            end += 1


        return ans if ans != sys.maxsize else 0
        
