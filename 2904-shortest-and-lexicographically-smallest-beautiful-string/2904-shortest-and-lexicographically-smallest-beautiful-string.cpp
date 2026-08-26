class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int no_ones=0;
        int len=INT_MAX;
        string ans="";
        int i=0,j=0;
        while(j<n){
            if(s[j]=='1') no_ones++;
            while(no_ones>k){
                if(s[i]=='1') no_ones--;
                i++;
            }
            if(no_ones==k){
                while(s[i]=='0') i++;
                string temp = s.substr(i, j - i + 1);
                if (temp.length() < len) {
                    ans = temp;
                    len = temp.length();
                }
                else if (temp.length() == len && temp < ans) {
                    ans = temp;
                }  
            }
            j++;
        }
        return ans;
    }
};