class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
       int count=1;
        for(auto i:s){
            if(st.empty()){
                st.insert(i);
                continue;
            }
            if(st.find(i)==st.end()){
                st.insert(i);
                continue;
            }
            if(st.find(i)!=st.end()){
                st.clear();
                st.insert(i);
                count++;
            }
        }
        return count;
    }
};