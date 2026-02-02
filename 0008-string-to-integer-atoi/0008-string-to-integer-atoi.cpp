class Solution {
public:
    long long findNum(string &s,int i,long long num){
        if(i>=s.size() || !isdigit(s[i])){
            return num;
        }
        if(num*10+(s[i]-'0')>=INT_MAX) return num*10+(s[i]-'0';
        else{
            num=num*10+(s[i]-'0');
        }

        return findNum(s,i+1,num);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(s[i]=='.') return 0;
        int sign=1;
        int signCount=0;
        while(i<s.size() && (s[i]=='+' || s[i]=='-')){
                signCount++;
                if(signCount==1){
                    sign=(s[i]=='+')?1:-1;
                }
                if(signCount>1) return 0;
                i++;
        }
        
        long long num=findNum(s,i,0);
        num=num*sign;
        if(num>=INT_MAX) return INT_MAX;
        if(num<=INT_MIN) return INT_MIN;
        return num;
    }
};