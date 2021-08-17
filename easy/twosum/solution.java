class Solution {
    public int[] twoSum(int[] nums, int target) {
        //create HashMap
        Map<Integer, Integer> numbers = new HashMap<Integer, Integer>();
        //make an array with the result to be returned (the indices in any order)
        int[] result = new int[2];
        
        // loop through the nums array to first check if a pair can be made with existing keys in map, and add the number (key) and its index (value) to the HashMap
        for (int i = 0; i < nums.length; i++) { 
            // doing this check before placing value in map allows checking for duplicates in array and avoiding overwriting duplicate
            int goal = target - nums[i];
            if (numbers.containsKey(goal)) {
                result[0] = numbers.get(goal);
                result[1] = i;
                //break to avoid running more code, reduce time
                break;
            }
            
            // add current number and its index if we are continuing
            numbers.put(nums[i], i);
        }
        
        return result;
    }
}

// test cases: small array, larger array, array with duplicates
