class Solution {
public:
    int binaryGap(int n) {
        vector<int> v;
        int ans=0;
        while(n>0){
            v.push_back(n%2);
            n/=2;
        }
        int i=0;
        while(i<v.size()){
            if(v[i]==1) break;
            else i++;
        }
        int preIdx=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]==1 && v[j-1]==1){
                ans=max(ans,j-preIdx);
                preIdx=j;

            } 
            else if(v[j]==1 && v[j-1]!=1){
                ans=max(ans,j-preIdx);
                preIdx=j;
            }
            }

        return ans;
        
    }
};