class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def helper(l, r) :
            if l == r : return nums[l]
            m = l + (r - 1) // 2
            leftMajor = helper(l, m)
            rightMaior = helper(m + 1, r)
            if leftMajor == rightMaior : return leftMajor
            leftCount = sum(1 for i in range(l, r + 1) if nums[i] == leftMajor)
            rightCount = sum(1 for i in range(l , r + 1) if nums[i] == rightMaior)
            return leftMajor if leftCount > rightCount else rightMaior

        return helper(0, len(nums) - 1)