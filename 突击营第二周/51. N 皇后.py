class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        sols = []
        def backtrack(pos, row) :
            if len(pos) == n and row == n :
                sols.append(pos)
            for col in range(n) :
                if all (row != row1 and col != col1 and abs(row - row1) != abs(col - col1) for row1, col1 in pos) :
                    backtrack(pos + [(row, col)], row + 1)
        backtrack([], 0)
        return [
            [''.join('Q' if (i, j) in sol else '.' for i in range(n)) for j in range(n)]
            for sol in sols
        ]