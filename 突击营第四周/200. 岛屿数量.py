class Solution:    
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0

        uf = {}
        N = len(grid)
        M = len(grid[0])

        for i in range(N):
            for j in range(M):
                if grid[i][j] == '1':
                    uf[(i,j)] = (i,j)

        for i in range(N):
            for j in range(M):
                if grid[i][j] == '0':
                    continue

                if i+1<N and grid[i+1][j] == '1':
                    union(uf, (i,j), (i+1,j))
                if j+1<M and grid[i][j+1] == '1':
                    union(uf, (i,j), (i,j+1))

        count = 0
        for k, v in uf.items():
            if v == k:
                count += 1
        return count

    def union(uf, a, b) -> None:
        uf[root(uf, b)] = root(uf, a)

    def root(uf, x) -> str:
        r = x
        while r != uf[r]:
            r = uf[r]
    return r
