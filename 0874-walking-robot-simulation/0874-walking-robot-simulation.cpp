class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& obstacles) {
        unordered_set<string> s;
        for(auto &it:obstacles){
            string temp=to_string(it[0])+"_"+to_string(it[1]);
            s.insert(temp);
        }
        int axis=2;
        int dir=1;
        int x=0,y=0;
        int maxdist=0;
        int n=c.size();
        for(int i=0;i<n;i++){
            if(c[i]==-1){
                if(axis==1){
                    dir=(dir==1)?-1:1;
                }
                axis=(axis==2)?1:2;
            }
            else if(c[i]==-2){
                if(axis==2){
                    dir=(dir==1)?-1:1;
                }
                axis=(axis==1)?2:1;
            }
            else{
                for(int k=0;k<c[i];k++){
                    int newx=x;
                    int newy=y;
                    if(axis==1) newx+=dir;
                    else newy+=dir;
                    string newtemp=to_string(newx)+"_"+to_string(newy);
                    if(s.find(newtemp)!=s.end()) break;
                    x=newx;
                    y=newy;
                }
            }
            maxdist=max(maxdist,x*x+y*y);
        }
        return maxdist;
    }
};