class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<int>st;
        for(auto i:s){
            if(i=='(')st.push('(');
            if(i==')')st.pop();
            int size=st.size();
            ans=max(ans,size);
            
        }
        return ans;
    }
};