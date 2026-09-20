class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int rd=0;
        for(int i=0;i<n;i++){
            int temp=(26-(s[i]-'a'))*(i+1);
            rd+=temp;
        }
        return rd;
    }
};