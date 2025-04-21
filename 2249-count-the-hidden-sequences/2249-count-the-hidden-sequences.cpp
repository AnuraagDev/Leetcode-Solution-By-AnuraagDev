class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long sum=0;
        long maxi=0;
        long mini=0;
        for(auto i:differences){
            sum+=i;
            maxi=max(maxi,sum);
            mini=min(mini,sum);
        }
        return max(0L,(upper-lower)-(maxi-mini)+1);
        
    }
};