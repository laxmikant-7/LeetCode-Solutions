class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int type0=0,type1=0,type2=0;
        for(auto stone:stones){
            int type=stone%3;
            if(type==0) type0++;
            else if(type==1) type1++;
            else type2++;
        }
        if(type0 % 2==0 && type1>=1 && type2>=1) return true;
        else if(type0 % 2==1 && ((type1-type2)>2 || (type2-type1>2))) return true;
        return false;
    }
};