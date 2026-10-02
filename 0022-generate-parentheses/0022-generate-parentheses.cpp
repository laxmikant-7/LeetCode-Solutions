class Solution {
public:
    bool check(string temp,int n){
        if(temp.size()<2*n) return false;
        int x=0;
        for(auto ch:temp){
            if(ch=='(') x++;
            else x--;
            if(x<0) return false;
        }
        return true;
    }
    void solve(int open_br,int close_br,vector<string> &ans,int n,string temp){
        if(open_br==0 && close_br==0){
            if(check(temp,n)) ans.push_back(temp);
            return;
        }
        if(open_br>0){
            temp.push_back('(');
            solve(open_br-1,close_br,ans,n,temp);
            temp.pop_back();
        }
        if(close_br>0){
            temp.push_back(')');
            solve(open_br,close_br-1,ans,n,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,ans,n,"");
        return ans;
    }
};