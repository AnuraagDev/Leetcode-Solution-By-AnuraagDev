class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int candidates1,candidates2;
        for(int i=0;i<nums.size();i++){
            if(count1==0&&nums[i]!=candidates2){
                count1++;
                candidates1=nums[i];
            }
            else if(count2==0&&nums[i]!=candidates1){
                count2++;
                candidates2=nums[i];
            }
            else if(candidates1==nums[i])count1++;
            else if(candidates2==nums[i])count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==candidates1)count1++;
            if(nums[i]==candidates2)count2++;
        }
        vector<int>a;
        int thres=nums.size()/3;
        if(count1>thres)a.push_back(candidates1);
        if(count2>thres&&candidates1!=candidates2)a.push_back(candidates2);
       
        return a;
    }
};