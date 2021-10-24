class Solution {
public:
    int maxArea(vector<int>& height) {
        //possible edge cases
        //empty height vector (return 0)
        //one height value (return 0)
        int lInd = 0;
        int rInd = height.size() - 1;
        int max = 0;
        while (lInd < rInd) {
            int area = abs((rInd - lInd) * min(height[lInd], height[rInd]));
            if (area > max) {
                max = area;
            }
            //iterate on the smaller side
            height[lInd] < height[rInd] ? ++lInd : --rInd;
        }
        return max;
    }
};
