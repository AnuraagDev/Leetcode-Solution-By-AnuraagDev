#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = arr.size();
        vector<int> xorpre(n);
        xorpre[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            xorpre[i] = xorpre[i - 1] ^ arr[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (int j = 0; j < queries.size(); ++j) {
            int left = queries[j][0];
            int right = queries[j][1];
            if (left == 0) {
                ans.push_back(xorpre[right]);
            } else {
                ans.push_back(xorpre[right] ^ xorpre[left - 1]);
            }
        }
        
        return ans;
    }
};
