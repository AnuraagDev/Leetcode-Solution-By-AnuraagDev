class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
  map<int,int>mp;

    bool book(int x, int y) {
        mp[x]++;
        mp[y]--;
        int ongoingEvents=0;
        for(auto&[time,change]:mp){
            ongoingEvents+=change;
            if(ongoingEvents>=3){
                mp[x]--;
                mp[y]++;
                return 0;
            }

        }
        return 1;
        }
       
    
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */