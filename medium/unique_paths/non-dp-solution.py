class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return math.floor(factorial(m + n - 2)/(factorial(m - 1) * factorial(n - 1)))
