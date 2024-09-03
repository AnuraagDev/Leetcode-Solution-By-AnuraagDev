class Solution {
public:
    int getLucky(string q, int k) {
        string s = "";
        
   
        for (auto i : q) {
            int num = i - 'a' + 1;
            s += to_string(num); 
        }
        
        while (k-- > 0) {
            int sum = 0;
            for (auto i : s) {
                sum += i - '0';
            }
            s = to_string(sum); 
            
            if (s.length() == 1) {  
                break;
            }
        }
        
        return stoi(s);  
    }
};
