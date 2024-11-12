class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items based on price
        sort(items.begin(), items.end());
        
        // Map to store the maximum beauty for each price
        map<int, int> maxBeautyMap;
        int maxBeauty = 0;
        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            maxBeautyMap[item[0]] = maxBeauty;
        }

        // Process each query to get the maximum beauty for the given price
        vector<int> result;
        for (int price : queries) {
            auto it = maxBeautyMap.upper_bound(price);
            if (it == maxBeautyMap.begin()) {
                result.push_back(0); // No valid price found
            } else {
                --it;
                result.push_back(it->second);
            }
        }
        
        return result;
    }
};
