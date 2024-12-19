class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n=arr.size();
        vector<int>arr1(arr.begin(),arr.end());
        sort(arr1.begin(),arr1.end());
        long long cnt=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-arr1[i];
            cnt+=(diff==0);
        }
        return cnt;
    }
};