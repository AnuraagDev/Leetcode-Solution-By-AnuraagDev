class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if(derived.size()==1)return derived[0]==0;
        bool flag=1;
        for(auto i:derived){
            if(i==1)flag=0;
        }
        if(flag)return 1;
        int x=0;
        int n=derived.size();
      
        for(int i=0;i<n;i++){
            x^=derived[i];
        }
        return x==0;
    }
};