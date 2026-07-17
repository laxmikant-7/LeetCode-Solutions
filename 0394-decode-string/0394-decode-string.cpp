class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<string> st1;
        string ans="";
        stack<int> st2;
        int currnum=0;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                currnum=(currnum*10)+(s[i]-'0');
            }
            else{
                if(s[i]=='['){
                    string temp="";
                    temp+=s[i];
                    st1.push(temp);
                    st2.push(currnum);
                    currnum=0;
                }
                else if(s[i]==']'){
                    string temp="";
                    while(!st1.empty() && st1.top()!="["){
                        temp=st1.top()+temp;
                        st1.pop();
                    }
                    st1.pop();
                    int num=st2.top();
                    st2.pop();

                        string tempans="";
                        for(int i=0;i<num;++i){
                            tempans+=temp;
                        }
                        st1.push(tempans);
                }
                else{
                    string temp="";
                    temp+=s[i];
                    st1.push(temp);
                }
            }
        }
        while(!st1.empty()){
            ans=st1.top()+ans;
            st1.pop();
        }
        return ans;
        
        
    }
};