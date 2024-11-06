class Solution {
    bool check(int a,int b){
        return __builtin_popcount(a) == __builtin_popcount(b);
    }
public:
    bool canSortArray(vector<int>& nums) {
        bool sorted=false;
         while (!sorted) {
            sorted = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    if (!check(nums[i], nums[i + 1])) {
                        return false;
                    }
                    swap(nums[i], nums[i + 1]);
                    sorted = false;
                }
            }
        }
        return 1;
    }
};