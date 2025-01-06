class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>Se;
        for(auto i:edges){
            if(Se.find(i[0])!=Se.end())return i[0];
            if(Se.find(i[1])!=Se.end())return i[1];
            Se.insert(i[0]);
            Se.insert(i[1]);
        }
        return 0;
    }
};