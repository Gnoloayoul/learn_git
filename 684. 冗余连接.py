class Solution:
    def findRedundantConnection(self, input: List[List[int]]) -> List[int]:
        # ģ�壺���������ʼ��
        self.edge = [[] for i in range(1001)]  # max n is 1000
        self.hasCycle = False
        for e in input:
            u, v = e[0], e[1]
            self.addEdge(u, v)
            self.addEdge(v, u)
            self.visit = [False] * 1001
            self.dfs(u, -1)
            if self.hasCycle:
                return e
        return []

    # ģ�壺DFS����ͼ�һ�
    def dfs(self, x, fa):
        self.visit[x] = True
        for y in self.edge[x]:
            if y == fa:
                continue
            if self.visit[y]:
                self.hasCycle = True
            else:
                self.dfs(y, x)

    # ģ�壺�ӱ�
    def addEdge(self, u, v):
        self.edge[u].append(v)