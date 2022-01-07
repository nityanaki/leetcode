class Solution:
    ### is it possible to pass by ref here??
    def find_partition(self, nums: List[int]) -> int:
      #minLarge is the min of the "large portion"
      #first number
        minLarge = nums[0]
      #maxSmall is the maximum of the "small portion"
      #last number in array
        maxSmall = nums[len(nums) - 1]

      # for no rotation:
        if minLarge <= maxSmall:
            return 0

      # o.w. if there is rotation
        start = 0
        end = len(nums) - 1
        while start <= end:
            mid = (start + end)//2
            if nums[mid - 1] > nums[mid]:
                return mid
            if nums[mid] >= minLarge:
                start = mid + 1
            else:
                end = mid - 1
    
        # prevent syntax error
        return -1
    
    # function that actually finds where the number is in the array
    # needs the partition (the index of the smallest # in the array)
    def find_num(self, nums:List[int], target:int, part:int) -> int:
        start = 0
        end = len(nums) - 1
        if part != 0:
            if target >= nums[0]:
                end = part - 1
            else:
                start = part
        
        # standard binary search
        while start <= end:
            mid = (start + end)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        
        return -1

    def search(self, nums: List[int], target: int) -> int:
        part = Solution.find_partition(self, nums)
        print(part)
        return Solution.find_num(self, nums, target, part)
