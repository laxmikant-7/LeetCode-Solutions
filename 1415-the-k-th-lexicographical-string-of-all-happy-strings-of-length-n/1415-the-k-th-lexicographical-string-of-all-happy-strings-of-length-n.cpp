class Solution {
public:
    void solve(string curr,vector<string> &temp,int n){
        if(curr.size()==n){
            temp.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(curr.size()!=0 && curr.back()==ch) continue;
            curr+=ch;
            solve(curr,temp,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        int no_strings=3*(1<<(n-1));
        if(no_strings<k) return "";
        vector<string> temp;
        solve("",temp,n);
        return temp[k-1];
    }
};