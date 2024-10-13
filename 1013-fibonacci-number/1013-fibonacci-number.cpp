class Solution {
public:
    int fib(int n) {
        if(n<2)return n;
        int initial=0;
        int initial2=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=initial+initial2;
            initial=initial2;
            initial2=ans;
        }
        return ans;
    }
};