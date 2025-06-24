class Solution {
public:int solve1(string a){
    char temp=-1;
    string ans=a;
    if(a[0]!='0')temp=a[0];
    else if(a[0]=='0'){
        for(auto i:a){
            if(i!='0'){temp=i;
            break;}
        }
    }
    if(temp==-1)return stoi(a);
    for(int i=0;i<a.size();i++){
        if(a[i]==temp)ans[i]='0';
    }
    return stoi(ans);
}

    int solve(string a){
        char temp=-1;
        string ans=a;
        if(a[0]!='9')temp=a[0];
        else{
            for(auto i:a){
                if(i!='9'){temp=i;
                break;}
            }

        }
        if(temp==-1)return stoi(a);
        for(int i=0;i<a.size();i++){
            if(a[i]==temp)ans[i]='9';
        }
        return stoi(ans);
        
    }
    int minMaxDifference(int num) {
        string nums=to_string(num);
        num=solve(nums);
        int dif=solve1(nums);
        return num-dif;
    }
};