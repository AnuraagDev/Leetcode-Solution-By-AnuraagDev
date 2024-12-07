class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
     int mini=0;
     for(auto i:candies)mini=max(mini,i);  
     int low=1;
     int high=mini;
     int ans=0;
     while(low<=high){
        int mid=(low+high)/2;
        if(solve(mid,candies,k)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
     }
     return ans; 
    }
    bool solve(int a,vector<int>&ca,long long k){
        long long count=0;
        for(auto i:ca){
            count+=1ll*(i/a);
        }
        return count>=k;

    }
};