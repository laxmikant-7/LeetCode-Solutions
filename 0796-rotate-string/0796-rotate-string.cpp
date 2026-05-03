class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int n1=goal.size();
        if(n!=n1) return false;
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(goal[i]==s[0]) temp.push_back(i);
        }
        if(temp.empty()) return false;
        for(int i=0;i<temp.size();i++){
            int idx=temp[i];
            for(;idx<temp[i]+n;idx++){
                if(goal[idx%n]!=s[idx-temp[i]]) break;
            }
            if(idx==temp[i]+n) return true;;
        }
        return false;
    }
};