class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int min_push=0;
        for(int i=0;i<word.size();i++){
            if(i<8) min_push++;
            else if(i<16) min_push+=2;
            else if(i<24) min_push+=3;
            else min_push+=4;
        }
        return min_push;
        
    }
};