class SegTree:
    def __init__(self, nums) -> None:
        self.nums = nums
        self.L = len(nums)
        self.tree = [0 for _ in range(4 * self.L)]
    def build(self):
        self._build(0, 0, self.L-1)
    def update(self, index, val):
        self._update(0, 0, self.L-1, index, val)
    def query(self, left, right):
        return self._query(0, 0, self.L-1, left, right)
    def _build(self, node, start, end):
        if start == end:
            self.tree[node] = self.nums[start]
            return
        mid = (start + end)//2 
        left_node = 2*node+1
        right_node = 2*node+2
        self._build(left_node, start, mid)
        self._build(right_node, mid+1, end)
        self.tree[node] = self.tree[left_node] + self.tree[right_node]
    def _update(self, node, start, end, index, val):
        if start == end:
            # self.nums[index] = val 
            self.tree[node] = val
            return
        mid = (start+end)//2
        left_node = node*2+1
        right_node = node*2+2
        if start <= index <= mid:
            self._update(left_node, start, mid, index, val)
        else:
            self._update(right_node, mid+1, end, index, val)
        self.tree[node] = self.tree[left_node] + self.tree[right_node]
    def _query(self, node, start, end, left, right):   
        if start > right or end < left: 
            return 0
        # 以下剪枝非常关键，否则会超时
        if left <= start and end <= right:
            return self.tree[node]
        if start == end:
            return self.tree[node]
        mid = (start+end)//2
        left_node = node*2+1
        right_node = node*2+2
        sum_left = self._query(left_node, start, mid, left, right)
        sum_right = self._query(right_node, mid+1, end, left, right)
        return sum_left + sum_right




class NumArray:

    def __init__(self, nums: List[int]):
        self.tree = SegTree(nums)
        self.tree.build()
    def update(self, index: int, val: int) -> None:
        self.tree.update(index, val)
    def sumRange(self, left: int, right: int) -> int:
        return self.tree.query(left, right)
