class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        //for size 2:
        //just reverse elements
        
        //edge cases?
        //[a, b]
        //rProds: b
        // out should be [b, a]
        if (nums.size() == 2) {
            out.push_back(nums[1]);
            out.push_back(nums[0]);
            return out;
        }
        
        
        // 1: (2 * 3 * 4)
        // 2: (1) * (3*4)
        // 3: (1* 2) * (4)
        // 4: (1 * 2 * 3)
        int lProd = 1;
        vector<int> rProds;
        int rProd = 1;
        //iterate through nums backwards
        for (int i = nums.size() - 1; i > 0; --i) {
            rProd *= nums[i];
            rProds.push_back(rProd);
        } // content should be 
        // 0: 4, 1: 12, 2: 24
        // iterate through nums forward
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0) {
                lProd *= nums[i-1];
            }
            int r = 1;
            if (i != nums.size() - 1)
                r = rProds[rProds.size() - 1 - i];
            int prod = lProd * r;
            out.push_back(prod);
        }
        
        return out;
    }
};
