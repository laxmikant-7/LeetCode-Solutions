class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcnt=0;
        int rcnt=0;
        int scnt=0;
        for(auto move:moves){
            if(move=='R') rcnt++;
            else if(move=='L') lcnt++;
            else scnt++;
        }
        if(lcnt+scnt>=rcnt+scnt){
            return (lcnt+scnt)-rcnt;
        }
        return (rcnt+scnt)-lcnt;
    }
};