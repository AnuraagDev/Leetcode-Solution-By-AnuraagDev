#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> mp(nums.begin(), nums.end());
        unordered_map<long long,int>m1;
        int maxStreak = 0;
        //sort(nums.begin(),nums.end());
        for (auto i : nums) {
            maxStreak = max(maxStreak, solve(i, mp,m1));
        }

        return maxStreak == 1 ? -1 : maxStreak;
    }

private:
    int solve(long long i, unordered_set<long long>& mp, unordered_map<long long,int>&m1) {
        if(m1.find(i)!=m1.end())return m1[i];
        if (mp.find(i * i) != mp.end()) {
            
            return m1[i]=1 + solve(i * i, mp,m1);
        }
        return m1[i] = 1; 
    }
};
