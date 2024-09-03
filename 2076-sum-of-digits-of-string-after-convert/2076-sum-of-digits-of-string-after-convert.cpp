class Solution {
public:
    int getLucky(string q, int k) {
        string s = "";
        
        // Convert each character in q to its corresponding numeric value
        for (auto i : q) {
            int num = i - 'a' + 1;
            s += to_string(num);  // Concatenate numeric values as string
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
