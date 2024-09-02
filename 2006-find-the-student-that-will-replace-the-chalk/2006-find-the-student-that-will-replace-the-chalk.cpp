class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long>pre(chalk.size());
        pre[0]=chalk[0];
        int n=chalk.size();
        for(int i=1;i<n;i++){
            pre[i]=chalk[i]+pre[i-1];
        }
        k=k%pre[n-1];
        for(int i=0;i<n;i++){
            if(k<chalk[i])return i;
            k-=chalk[i];
        }return 0;   
    }
};