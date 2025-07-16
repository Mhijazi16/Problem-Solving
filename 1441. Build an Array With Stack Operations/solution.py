
from typing import List


# 1 2 3 
# [1,3]
# [1, 3]
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        index = 0
        shift = 0

        for i in range(1,n+1): 
            if i - 1 == target[-1]: 
                return ans

            if i == target[index]: 
                while shift: 
                    ans.append("Pop")
                    shift -= 1
                index += 1
            else: 
                shift += 1

            ans.append("Push")
        return ans



