class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sum=0;
        stack<int>st;
        for(auto i:tokens){
            if(i=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a+b;
                st.push(c);
                }
                else if(i=="*"){
                    int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a*b;
                st.push(c);
                }else if(i=="-"){
                    int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b-a;
                st.push(c);
                }else if(i=="/"){
                    int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b/a;
                st.push(c);
                }
                else {
                    st.push(stoi(i));
                }
        }
    return st.top();
    }
};