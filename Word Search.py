class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[i])):
                if self.dfs(i,j,board,word):
                    return True
        
        return False
    
    def dfs(self, i, j, board, word):
        if len(word)==0:
            return True
        if i>=len(board) or i<0 or j<0 or j>=len(board[i]) or board[i][j]!=word[0] :
            return False
        ch = board[i][j]
        board[i][j] = '.'
        ans =  self.dfs(i+1,j,board,word[1:]) or self.dfs(i,j+1,board,word[1:]) or self.dfs(i-1,j,board,word[1:]) or self.dfs(i,j-1,board,word[1:])
        board[i][j] = ch
        return ans