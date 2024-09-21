bool compare(int a,int b){
    string aa=to_string(a);
    string bb=to_string(b);
    return aa<bb;
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++)ans.push_back(i);
        sort(ans.begin(),ans.end(),compare);
        return ans;
    }
};