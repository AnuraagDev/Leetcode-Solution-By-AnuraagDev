class Solution {
public:
    int minAddToMakeValid(string s) {
     stack<char>st;
     for(auto i:s){
        if(st.empty()){
            st.push(i);
            continue;
        }
        else if(st.top()=='('&&i==')'){
            st.pop();
            continue;
        }
        else{
            st.push(i);
        }

     }  return st.size();
    }
};