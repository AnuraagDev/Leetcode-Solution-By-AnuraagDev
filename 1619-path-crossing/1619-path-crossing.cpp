class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>>se;
        int x=0;
        int y=0;
        se.insert({0,0});
        for(auto i:path){
            if(i=='N')y++;
            else if(i=='S')y--;
            else if(i=='W')x--;
            else  x++;
            if(se.find({x,y})!=se.end())return 1;
            se.insert({x,y});
        }
        return 0;
    }
};