class Solution {
public:
    bool is(int n){
        int b=sqrt(n);
        return b*b==n;
    }
    int bulbSwitch(int n) {
        int count=0;
        for(int i=n;i>0;i--){
            if(is(i)){
               return sqrt(i);
            }
        }
        return 0;
    }
};