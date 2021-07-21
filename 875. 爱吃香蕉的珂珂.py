#主体思路：二分答案 判定+二分
#注意细节：
#1、定义域，小家伙吃香蕉的速度，左边界是1，而不是数组的最小值，可能是python3的语言特性
#2、向上取整，或者返回大于或等于x的整数，python3有自己的写法

class Solution:
    def need(self, cur: int, piles: List[int]) -> int:
        #向上取整写法1：(p + cur - 1) // cur
        return sum((p + cur - 1) // cur for p in piles)
        #向上取整写法2: math.ceil(p / cur)
        #即：
        #return sum(math.ceil(p / cur) for p in piles)

#没什么好说的，二分模板（1.1）的变体
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left,right = 1, max(piles)
        while left < right:
            mid = (left + right) >> 1
            if self.need(mid, piles) <= h : right = mid 
            else: left = mid + 1
        return left