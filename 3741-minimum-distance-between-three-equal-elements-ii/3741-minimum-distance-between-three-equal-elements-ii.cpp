class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int mindist=INT_MAX;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        for(auto &[num,v]:m){
            if(v.size()<3) continue;
            else{
                for(int j=0;j<v.size();j++){
                    int idx1=j;
                    int idx2=j+2;
                    if(idx2<v.size()){
                        mindist=min(mindist,v[idx2]-v[idx1]);
                    }
                }
            }
        }
        return (mindist==INT_MAX)?-1:2*mindist;
    }
};