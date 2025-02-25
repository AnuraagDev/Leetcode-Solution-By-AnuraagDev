class Solution {
    int mod=1e9+7;
    public: int numOfSubarrays(vector<int>& arr) {
        int presum = 0, oddC= 0, evenC= 1, ans = 0;
        for (int num:arr) {
            presum += num;
            if (presum % 2 == 0) {
                ans=(ans%mod + oddC%mod)%mod;
                evenC++;
            } else {
                ans = (ans%mod+evenC%mod)%mod;
                oddC++;
            }
        }
        return ans;
    }
};