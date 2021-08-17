class Solution {
    public int[] twoSum(int[] nums, int target) {
        // create the iterating ints: one for beginning of array, one for end
        int begInd = 0;
        int endInd = nums.length - 1;
        // create a while loop: while begInd < endInd (when they're equal then it wouldn't be possible to find a solution)
        boolean match = false;
        while (!match && begInd < endInd) {
            // find goal int: this is target - nums[begInd]
            int goal = target - nums[begInd];
            // keep decrementing endInd until either reaching goal or getting to a number smaller than goal
            while (nums[endInd] >= goal && endInd > begInd) {  ///**** in an interview, i would perform a test case here since i may be using this logic wrong (off by 1)
                if (nums[endInd] == goal) {
                    match = true;
                }
                if (match) break;
                endInd--;
            }
            // break loop once we reach the goal (instead of breaking another option would be changing the loop so that we have some boolean 'match': since there will definitely be a solution)
            // increment beg by 1, keep end ind constant
            if (!match) {
                ++begInd;
            }
        }
        // there will definitely be a solution (according to problem description), so return begInd and endInd
        int[] arr = {begInd + 1, endInd + 1};
        return arr;
    }
}

// if a number is larger than target then just ignore it
// idea: we have a sorted array; for the example array [2,7,11,15] for example, and target 9, we want 7 next: go through the end of the array until reaching 7; if we don't ever find 7 (if we reach a number less than 7), then go up to the next # and continue from where we left off
// [2, 3, 4, 7, 8] target 9
// 2: 8 -> 7 (stop)
// if 7 doesn't exist, then we reach 4 (or a number smaller than 7) and pause there
// keep going until the pointers reach each other
// O(N) complexity
