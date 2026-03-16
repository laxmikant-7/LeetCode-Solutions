class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1=g.size();
        int total=0;
        sort(s.begin(),s.end());
        for(int i=0;i<n1;i++){
            int low=0;
            int high=s.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(s[mid]>=g[i]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(low!=s.size()){
                total++;
                s.erase(s.begin() + low);
            }
        }
        return total;
    }
};