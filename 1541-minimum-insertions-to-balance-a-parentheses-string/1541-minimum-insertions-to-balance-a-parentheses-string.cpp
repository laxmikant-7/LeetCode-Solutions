class Solution {
public:
    int minInsertions(string s) {
        string newS="";
        int n=s.size();
        int f=0;
        for(int i=0;i<n;){
            if(s[i]=='(') newS.push_back('(');
            else{
                newS.push_back(')');
                if(i==n-1 || s[i+1]!=')') f++;
                else i++;
            }
            i++;
        }
        int need=0,x=0;
        for(int i=0;i<newS.size();i++){
            if(newS[i]=='(') x++;
            if(newS[i]==')') x--;
            if(x<0){
                need+=1;
                x=0;
            }
        }
        if(x>0) need+=(x*2);
        return f+need;
    }
};