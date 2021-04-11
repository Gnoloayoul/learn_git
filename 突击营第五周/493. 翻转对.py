class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def func(left = 0, right = len(nums) - 1):

            if left >= right: return 0

            mid = left + ((right-left)>>1)
            count = func(left, mid) + func(mid+1, right)

            index_i = left
            for rightNumber in nums[mid+1 : right+1]:
                while index_i <= mid and nums[index_i] <= rightNumber * 2:
                    index_i += 1
                count += mid + 1 - index_i
                if index_i > mid: break

            nums[left : right+1] = sorted(nums[left : right+1])

            return count

        return func()