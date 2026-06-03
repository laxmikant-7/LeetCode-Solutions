class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n1=ls.size();
        int n2=ws.size();
        int ans=INT_MAX;

        vector<int> temp1;
        for(int i=0;i<n1;i++){
            temp1.push_back(ls[i]+ld[i]);
        }
        sort(temp1.begin(),temp1.end());
        for(int i=0;i<n2;i++){
            int st=ws[i];
            int dur=wd[i];
            if(st<=temp1[0]){
                ans=min(ans,temp1[0]+dur);
            }
            else{
                ans=min(ans,st+dur);
            }
        }
        vector<int> temp2;
        for(int i=0;i<n2;i++){
            temp2.push_back(ws[i]+wd[i]);
        }
        sort(temp2.begin(),temp2.end());
        for(int i=0;i<n1;i++){
            int st=ls[i];
            int dur=ld[i];
            if(st<=temp2[0]){
                ans=min(ans,temp2[0]+dur);
            }
            else{
                ans=min(ans,st+dur);
            }
        }
        return ans;
    }
};