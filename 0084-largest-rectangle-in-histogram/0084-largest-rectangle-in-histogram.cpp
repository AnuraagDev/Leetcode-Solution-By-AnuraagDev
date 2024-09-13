class Solution {
public:
    vector<int> ps(vector<int> &height) {
        vector<int> p(height.size());
        stack<int> s;
        for (int i=0;i<height.size();i++) {
            while (!s.empty()&&height[s.top()]>=height[i]) {
                s.pop();}
            if (s.empty()) {p[i] = -1;} 
            else {p[i]=s.top();} 
            s.push(i);}
        return p;}
    vector<int> ns(vector<int> &height) {
        vector<int> n(height.size());
        stack<int> s;
        for (int i=height.size()-1;i>= 0;i--) {
            while (!s.empty() && height[s.top()] >= height[i]) {
                s.pop();}
            if (s.empty()) {n[i] = height.size();} 
            else {n[i] = s.top();}
            s.push(i);}
        return n;}
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        vector<int>son=ps(heights);
        vector<int>uph=ns(heights);
        for (int i=0;i<heights.size();i++) {
            int cur=(uph[i]-son[i]-1)*heights[i];
            maxi=max(cur,maxi);}
        return maxi;    }};