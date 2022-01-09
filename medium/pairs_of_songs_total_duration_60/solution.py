class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        countPairs = 0
        #array with 60 empty slots representing remainders
        countArr = [0] * 60
        
        for t in time:
            remain = t % 60
            diff = (60 - remain) % 60
            # search for diff in countArr to make the right pair
            countPairs += countArr[diff]
            countArr[remain] += 1
            
        return countPairs
