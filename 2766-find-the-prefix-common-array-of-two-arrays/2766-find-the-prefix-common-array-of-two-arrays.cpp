class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>mp(A.size()+1,0);
        vector<int>ans(A.size());
       int common=0;
        for(int i=0;i<A.size();i++){
            if(++mp[A[i]]==2)common++;
            if(++mp[B[i]]==2)common++;
            ans[i]=common;
            }
        return ans;
    }
};