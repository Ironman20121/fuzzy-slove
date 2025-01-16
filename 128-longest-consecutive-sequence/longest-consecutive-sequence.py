class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # # using sets to avoid dublicate ele
        # num_set = set(nums)
        # # using ans as we can multiple long group max will be our answer
        # ans = 0
        # # time and space 0(N)
        # for num in nums:
        #     # finding if it left element of not it is first of a like 
        #     if (num -1) not in num_set:
        #         length = 0
        #         # now we are check next number in set instead of sorting it as sorting takes O(nlogn)
        #         while num+length in num_set:
        #             length+=1
        #         ans = max(ans,length)
        # return ans
        mp = defaultdict(int)
        res = 0

        for num in nums:
            if not mp[num]:
                mp[num] = mp[num - 1] + mp[num + 1] + 1
                mp[num - mp[num - 1]] = mp[num]
                mp[num + mp[num + 1]] = mp[num]
                res = max(res, mp[num])
        return res
        
        