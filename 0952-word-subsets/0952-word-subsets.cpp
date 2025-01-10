class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         vector<int>total(26,0);
         for(auto wo:words2){
            vector<int> tempCharFreq(26,0);
            for(auto j:wo){
                tempCharFreq[j-'a']++;
            }
            for(int i=0;i<26;i++){
                total[i]=max(total[i],tempCharFreq[i]);
            }
         }
    vector<string>ans;
    for(auto wo:words1){
          vector<int> tempCharFreq(26,0);
            for(auto j:wo){
                tempCharFreq[j-'a']++;
            }
            bool flag=1;
            for(int i=0;i<26;i++){
                if(tempCharFreq[i]<total[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.push_back(wo);
            }

    }
    return ans;
        
    }
};