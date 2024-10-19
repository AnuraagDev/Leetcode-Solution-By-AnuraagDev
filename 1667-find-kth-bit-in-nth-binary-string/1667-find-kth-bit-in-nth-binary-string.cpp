class Solution {
public:
    string helper(int n,string res){ //n=2 , res=""   what if n=3
        if(n==1) return "0";
        else{
            // need to somehow call helper(n-1)
            string newres = helper(n-1,res); //newres = "0" | helper(2,res) res="011" | helper(1,res) res="0"
            string inverted = invert(newres);//inverted = "1" | 100
            reverse(inverted.begin(),inverted.end()); //"011" 
            res=newres + '1' +inverted;// 0111001
        }
        return res;
    }
    string invert(const string &s) { 
        string inverted = s;
        for (int i = 0; i < inverted.size(); ++i) {
            inverted[i] = (inverted[i] == '1') ? '0' : '1';
        }
        return inverted;
    }
    char findKthBit(int n, int k) {
        // initial thoughts: memoization? can have a bound on k 
        // so as to not create string past the kth ele how?
        string res=helper(n,res);

        return res[k-1];
        
    }
};