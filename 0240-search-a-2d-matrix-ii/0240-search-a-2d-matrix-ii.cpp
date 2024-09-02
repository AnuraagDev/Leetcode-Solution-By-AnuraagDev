class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int col=matrix[0].size()-1;
        while(row<matrix.size()&&col>=0){
            int num=matrix[row][col];
            if(num==target)return 1;
            if(num>target)col--;
            if(num<target)row++;
        }return 0;
    }
};