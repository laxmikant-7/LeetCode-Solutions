class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            int temp_size=s.size();
            for(int i=0;i<temp_size;i++){
                char ch=s[i];
                ch++;
                s.push_back(ch);
            }
        }
        return s[k-1];
    }
};