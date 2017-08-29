# -*- coding:utf-8 -*-


#
# Given a 2D board and a word, find if the word exists in the grid.
#
#
# The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
#
#
#
# For example,
# Given board = 
#
# [
#   [&#39;A&#39;,&#39;B&#39;,&#39;C&#39;,&#39;E&#39;],
#   [&#39;S&#39;,&#39;F&#39;,&#39;C&#39;,&#39;S&#39;],
#   [&#39;A&#39;,&#39;D&#39;,&#39;E&#39;,&#39;E&#39;]
# ]
#
#
# word = "ABCCED", -&gt; returns true,
# word = "SEE", -&gt; returns true,
# word = "ABCB", -&gt; returns false.


class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False
    
    # check whether can find word, start at (i,j) position    
    def dfs(self, board, i, j, word):
        if len(word) == 0: # all the characters are checked
            return True
        if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or word[0]!=board[i][j]:
            return False
        tmp = board[i][j]  # first character is found, check the remaining part
        board[i][j] = "#"  # avoid visit agian 
        # check whether can find "word" along one direction
        res = self.dfs(board, i+1, j, word[1:]) or self.dfs(board, i-1, j, word[1:]) \
        or self.dfs(board, i, j+1, word[1:]) or self.dfs(board, i, j-1, word[1:])
        board[i][j] = tmp
        return res
                
        
        
        
