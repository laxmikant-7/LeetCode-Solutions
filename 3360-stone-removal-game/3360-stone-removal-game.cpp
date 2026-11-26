class Solution {
public:
    bool canAliceWin(int n) {
        int turn=1; //1->alice
        int f=10;
        while(n>=f && n>0){
            n-=f;
            f--;
            turn=(turn==1)?0:1;
        }
        return (turn==1)?false:true;
    }
};