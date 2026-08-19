class Solution {
public:
    int find(vector<bool> &temp){
        int ans=0;
        if(temp[2] && temp[3] && temp[4] && temp[5]){
            ans+=1;
            temp[2]=false;
            temp[3]=false;
            temp[4]=false;
            temp[5]=false;
        }
        if(temp[4] && temp[5] && temp[6] && temp[7]){
            ans+=1;
            temp[4]=false;
            temp[5]=false;
            temp[6]=false;
            temp[7]=false;
        }
        if(temp[6] && temp[7] && temp[8] && temp[9]){
            ans+=1;
            temp[6]=false;
            temp[7]=false;
            temp[8]=false;
            temp[9]=false;
        }
        return ans;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin(),rs.end());
        int ans=0;
        int always=1;
        for(int i=0;i<rs.size();){
            int row=rs[i][0];
            if(row!=always){
                ans+=2;
                always+=1;
                continue;
            }
            else{
                always+=1;
            }
            vector<bool> temp(11,true);
            while(i<rs.size() && rs[i][0]==row){
                int seat=rs[i][1];
                temp[seat]=false;
                i++;
            }
            ans+=find(temp);
        }
        int lastrow=rs[rs.size()-1][0];
        ans+=2*(n-lastrow);
        return ans;
    }
};