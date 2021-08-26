// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         //brute force:
//         //somehow find ever combination of three numbers and compare their values
//         //this would mean go through the array and pick first number and keep going through, like 1-2-3, 1-2-4, 1-3-4, 2-3-4
//         //this would be pretty time consuming, big O approximately O(n^3)
        
//         //try this brute force solution:
//         //select first number in three-num combo, iterate from 0 to n-1
//         //the index is i
//         int maxProduct = nums.at(0)*nums.at(1)*nums.at(2);
//         // int maxProduct = -12;
//         for (int i = 0; i < nums.size()-2; i++) {
//             int iprod = nums.at(i);
//             for (int j = i+1; j < nums.size()-1; j++) {
//             //select second number in three-num combo, iterate from i+1 to n-1
//             //the index is j
//                 int jprod = iprod*nums.at(j);
//                 //select third number in three-num combo, iterate from j+1 to n-1
//                 //the index is k
//                 for (int k = j+1; k < nums.size(); k++) {
//                     int kprod = jprod*nums.at(k);
//                     if (kprod > maxProduct) {
//                         //multiply the three numbers together and compare to the max                            product
//                         maxProduct = kprod;
//                     }
//                 }
//             } 
//         }
//         return maxProduct;
        
//     }
// };

// brute force by itself works for 71/91 test cases, then exceeds runtime


// consulted solutions for help
// sorting solution

class Solution {
    public:
     int maximumProduct(vector<int>& nums) {
         std::sort(nums.begin(), nums.end());
         return std::max(nums.at(0)*nums.at(1)*nums.at(nums.size()-1), nums.at(nums.size()-1)*nums.at(nums.size()-2)*nums.at(nums.size()-3));
     }  
};
