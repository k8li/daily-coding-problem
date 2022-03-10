class Solution:
    def isboxValid(self, box: List[List[str]], size) -> bool:
        for i in range(size):
            for j in range(size):
                for k in range(size):
                    # Check whether each sublist has a repeating number
                    if box[i][j] == box[i][k]:
                        return False
                    
                    # Check whether one index of each sublist has a repeating number
                    if box[j][i] == box[j][i]:
                        return False
                    
        return True
    
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        if not isboxValid(board, 9) == False: return False
        
        for i in [0,3,6]:
            for j in [0,3,6]:
                if not isboxValid(board[i:i+2][j:j+2], 3): return False
        
        # Check each box.
        # fix one value, check equal for 3 values, then shift to next
        # this is a 3x3 version of the 9x9 board.
      
        return True
        
