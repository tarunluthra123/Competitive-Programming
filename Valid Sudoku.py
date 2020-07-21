class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c == '.':
                    continue
                p, q, r = (c, i, 'r'), (c, j, 'c'), (c, i//3, j//3)
                if (p in seen) or (q in seen) or (r in seen):
                    return False
                seen.add(p)
                seen.add(q)
                seen.add(r)
        return True
