class Solution {
public:

    int divide(int d, int r) {
        if(d==-2147483648&&r==-1)return 2147483647;
       return(long long)d/r;
    }
};