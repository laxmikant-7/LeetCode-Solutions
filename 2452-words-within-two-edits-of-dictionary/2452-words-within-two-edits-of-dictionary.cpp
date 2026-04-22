class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int n=q[0].size();
        for(auto s1:q){
            for(auto s2:d){
                int count=0;
                for(int i=0;i<n;i++){
                    if(s1[i]!=s2[i]) count++;
                    if(count>2) break;
                }
                if(count>2) continue;
                ans.push_back(s1);
                break;
            }
        }
        return ans;
    }
};