class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto i:operations){
            if(i=="C"){
                st.pop();
            }
            else if(i=="D"){
                st.push(st.top()*2);
            }
            else if(i=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                int c=a+b;
                st.push(a);
                st.push(c);
                
            }
            else{
                st.push(stoi(i));
            }
        }
        int count=0;
        while(!st.empty()){
            count+=st.top();
            st.pop();
        }
        return count;
    }
};