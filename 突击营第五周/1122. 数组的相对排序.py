class Solution:    
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        nums = {x : y for y, x in enumerate(arr2)}

        def cmpfunc(x) :
            if x not in nums :
                return 1
            return nums.get(x)

        def cmpagn(x) :
            if x in nums :
                return -1
            return x

        arr1.sort(key = cmpfunc)
        arr1.sort(key = cmpagn)
        return arr1