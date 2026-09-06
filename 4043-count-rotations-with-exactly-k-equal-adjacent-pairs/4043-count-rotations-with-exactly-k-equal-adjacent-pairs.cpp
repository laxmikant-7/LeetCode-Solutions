class Solution {
public:
    int find(string s){
        int score=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) score++;
        }
        return score;
    }
    int countRotations(string s, int k) {
        int n=s.size();
        string temp=s;
        int cnt=0;
        for(int i=0;i<n;i++){
            temp=temp.substr(1,n-1)+temp.substr(0,1);
            int score=find(temp);
            if(score==k) cnt++;
        }
        return cnt;
    }
};