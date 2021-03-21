class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums :
            return []
        res = []
        self.helper(res, nums, [])
        return res
    def helper(self, res, nums, path) :
        if not nums :
            res.append(path)
            return 
        dic = {x : 1 for x in nums}
        for i in range(len(nums)) :
            if dic[nums[i]] == 1 :
                self.helper(res, nums[:i] + nums[i + 1:], path + [nums[i]])
                dic[nums[i]] -= 1