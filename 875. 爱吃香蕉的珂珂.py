#����˼·�����ִ� �ж�+����
#ע��ϸ�ڣ�
#1��������С�һ���㽶���ٶȣ���߽���1���������������Сֵ��������python3����������
#2������ȡ�������߷��ش��ڻ����x��������python3���Լ���д��

class Solution:
    def need(self, cur: int, piles: List[int]) -> int:
        #����ȡ��д��1��(p + cur - 1) // cur
        return sum((p + cur - 1) // cur for p in piles)
        #����ȡ��д��2: math.ceil(p / cur)
        #����
        #return sum(math.ceil(p / cur) for p in piles)

#ûʲô��˵�ģ�����ģ�壨1.1���ı���
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left,right = 1, max(piles)
        while left < right:
            mid = (left + right) >> 1
            if self.need(mid, piles) <= h : right = mid 
            else: left = mid + 1
        return left