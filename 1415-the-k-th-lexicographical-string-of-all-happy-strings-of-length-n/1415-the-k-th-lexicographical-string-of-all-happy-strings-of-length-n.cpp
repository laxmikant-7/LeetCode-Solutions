class Solution {
public:
    void solve(string curr,string &ans,int n,int &count,int k){
        if(curr.size()==n){
            count++;
            if(count==k) ans=curr;
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(curr.size()!=0 && curr.back()==ch) continue;
            curr+=ch;
            solve(curr,ans,n,count,k);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string ans="";
        int count=0;
        solve("",ans,n,count,k);
        return ans;
    }
};