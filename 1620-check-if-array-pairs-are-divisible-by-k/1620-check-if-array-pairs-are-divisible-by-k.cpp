class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       vector<int>freq(k,0);
       for(auto num:arr){
        int remain=((num%k)+k)%k;
        freq[remain]++;

       }
       if(freq[0]%2!=0)return 0;
         for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) return false; 
        }
        
        return true;
    }
};