class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num;
        int i = 0; 
        int j = 0; 
        while (i != m && j != n) {
            if (nums1[i] <= nums2[j]) {
                num.push_back(nums1[i]);
                i++;
            } else {
                num.push_back(nums2[j]);
                j++;
            }
        }

       
        while (i < m) {
            num.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            num.push_back(nums2[j]);
            j++;
        }
    nums1.clear();
        
        for (int k = 0; k < num.size(); k++) {
           nums1.push_back(num[k]);
            
        }
        
    }
};
