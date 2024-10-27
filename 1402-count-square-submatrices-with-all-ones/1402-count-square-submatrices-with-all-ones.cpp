class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0) continue;
                matrix[i][j]=1+min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]});
            }
        }
        int count=0;
        for(auto i:matrix){
            for(auto j:i){
                count+=j;
            }
        }
        return count;
    }

};