class Solution {
public:
    int maxDepth(string s) {
        int max_dpt=0;
        int temp=0;
        for(auto brct:s){
            if(brct!='(' && brct!=')') continue;
            else if(brct=='(') temp++;
            else temp--;
            max_dpt=max(temp,max_dpt);
        }
        return max_dpt;
    }
};