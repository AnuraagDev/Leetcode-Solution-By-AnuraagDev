class Solution {
public:
   
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto i:nums){
            string a=to_string(i);
            if(a.length()%2==0)count++;
        }
        return count;
    }
};