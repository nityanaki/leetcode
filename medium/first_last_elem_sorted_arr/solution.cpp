class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int last = nums.size() - 1;
        int ind = -1;
        while (start <= last) {
            int mid = (start + last)/2;
            if (target == nums[mid]) {
                ind = mid;
                break;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                // target is less than nums[mid]
                last = mid - 1;
            }
        }
        if (ind == -1) {
            return {-1, -1};
        }
        // iterate through manually l and r to find the first and last indices
        int first = ind;
        last = ind;
        //first and last will be non inclusive
        while (first >= 0 && nums[first] == target) {
            --first;
        }
        while (last < nums.size() && nums[last] == target) {
            ++last;
        }
        return {first + 1, last - 1};
    }
};
