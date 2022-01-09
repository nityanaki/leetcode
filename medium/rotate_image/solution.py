class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        # formula is (c, n - 1 - r)
        # loop through the matrix
        for r in range((len(matrix)+1)//2):
            for c in range(len(matrix[0])//2):
                # do 4 way swap
                temp = matrix[r][c]
                matrix[r][c] = matrix[n - 1 - c][r]   
                matrix[n - 1 - c][r] = matrix[n - 1 - r][n - 1 - c]
                matrix[n - 1 - r][n - 1 - c] = matrix[c][n - 1 - r]
                matrix[c][n - 1 - r] = temp
