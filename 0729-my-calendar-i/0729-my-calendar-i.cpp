class MyCalendar {
public:
char speedUp = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'z';
}();
unordered_map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int x, int y) {
        for(auto i:mp){
            int a=i.first;
            int b=i.second;
         if(!(y<=a||x>=b))return 0;

        }
        mp[x]=y;
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */