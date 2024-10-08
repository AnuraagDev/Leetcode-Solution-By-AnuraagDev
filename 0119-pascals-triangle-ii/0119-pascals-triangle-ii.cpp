class Solution {
public:
    vector<int> getRow(int rowIndex) {
         {
            int numRows=rowIndex+1;
        vector<vector<int>>triangle(numRows);
        for(auto i=0;i<numRows;i++){
            triangle[i].resize(i+1);
            triangle[i][0]=1;
            triangle[i][i]=1;
        }
        for(auto i=1;i<numRows;i++){
            for(auto j=1;j<i;j++){
              
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];                
        }}
        return triangle[rowIndex];
    }
    }
};