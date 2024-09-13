class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>xorpre(arr.size());
        xorpre[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            xorpre[i]=xorpre[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto i:queries){
            if(i[0]==0)ans.push_back(xorpre[i[1]]);
            else{
                ans.push_back(xorpre[i[1]]^xorpre[i[0]-1]);
            }
        }return ans;
    }
};