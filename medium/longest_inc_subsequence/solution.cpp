class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                } //if
            } //for j
        } //for i
        
        int maximum = memo[0];
        for (size_t i = 0; i < memo.size(); ++i) {
            maximum = max(maximum, memo[i]);
        } //for i
        return maximum;
    }
};
