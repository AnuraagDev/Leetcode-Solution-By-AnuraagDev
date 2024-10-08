class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        for(auto i:s){
            if(i=='[')ans++;
            else if(ans>0)ans-=1;
        }
        return (ans+1)/2;
    }
};