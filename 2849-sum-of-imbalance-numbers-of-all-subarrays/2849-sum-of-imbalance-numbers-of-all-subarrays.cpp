class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int t=0;
            vector<int> vis(1005, 0); 
            vis[nums[i]]=1;
            for(int j=i+1; j<nums.size(); j++){
                if(vis[nums[j]]==1){
                    ans+=t;
                    continue;
                }
                vis[nums[j]]=1;
                if(vis[nums[j]+1]==1 && vis[nums[j]-1]==1){
               
                    t--;
                    ans+=t;
                    continue;
                }  
                if(vis[nums[j]+1]==1 || vis[nums[j]-1]==1){
                   
                    ans+=t;

                }  
                else{
                    t++;
                    ans+=t;
                }
            }
        }
        return ans;
    }
};