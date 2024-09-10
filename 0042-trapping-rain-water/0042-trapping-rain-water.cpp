class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int waterCap = 0;
        for (int i = 0; i < height.size(); i++) {
            waterCap += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return waterCap;
    }
};