class Solution {
public:
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> dup = arr;
    if(arr.empty())return {};
    sort(dup.begin(), dup.end());
    map<int, int> mp;
    
    mp[dup[0]] = 1;
    for (int i = 1; i < dup.size(); i++) {
        if (dup[i] > dup[i - 1]) {
            mp[dup[i]] = mp[dup[i - 1]] + 1;
        } else {
            mp[dup[i]] = mp[dup[i - 1]];
        }
    }
    
    vector<int> res;
    for (int x : arr) {
        res.push_back(mp[x]);
    }
    
    return res;
}

};