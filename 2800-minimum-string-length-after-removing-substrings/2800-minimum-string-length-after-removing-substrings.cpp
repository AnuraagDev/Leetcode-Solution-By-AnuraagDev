class Solution {
public:
    int minLength(string s) {
        stack<int>st;
        for(auto i:s){
            if(st.empty()){st.push(i);continue;}
            if(st.top()=='A'&&i=='B'){st.pop(); continue;}
            if(st.top()=='C'&&i=='D'){st.pop(); continue;}
            st.push(i);
        }
return st.size();    }
};