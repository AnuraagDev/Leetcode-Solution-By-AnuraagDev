  bool compare(int a,int b){
        string ab=to_string(a);
        string ba=to_string(b);
        if(ab+ba>ba+ab)return 1;
        return 0;
    }
class Solution {
public:
  

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        if(nums[0]==0)return "0";
        string a="";
        for(auto i:nums){
            a+=to_string(i);
        }
        return a;
    }
};