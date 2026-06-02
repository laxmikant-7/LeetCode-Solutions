class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n1=ls.size();
        int n2=ws.size();
        int ans=INT_MAX;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int lst=ls[i];
                int ldu=ld[i];
                int wst=ws[j];
                int wdu=wd[j];
                //plan1
                int t1=lst+ldu;
                if(wst<=t1){
                    t1+=wdu;
                }
                else{
                    int gap=wst-t1;
                    t1+=(gap+wdu);
                }
                //plan2
                int t2=wst+wdu;
                if(lst<=t2){
                    t2+=ldu;
                }
                else{
                    int gap=lst-t2;
                    t2+=(gap+ldu);
                }
                ans=min(ans,min(t1,t2));
            }
        }
        return ans;
    }
};