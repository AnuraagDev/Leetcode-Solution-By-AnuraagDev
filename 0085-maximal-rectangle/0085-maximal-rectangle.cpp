class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                int ele=st.top();
                st.pop();
                int nextSmaller=i;int previousSmaller=st.empty()==1?-1:st.top();
                maxArea=max(maxArea,heights[ele]*(nextSmaller-previousSmaller-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nextSmaller=heights.size();
            int ele=st.top();st.pop();
            int previousSmaller=st.empty()==1?-1:st.top();
            maxArea=max(maxArea,heights[ele]*(nextSmaller-previousSmaller-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>heights(matrix[0].size(),0);
        int maxHeight=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1')heights[j]++;
                else heights[j]=0;
            }
maxHeight=max(maxHeight, largestRectangleArea(heights));

        }
        return  maxHeight;
    }
};