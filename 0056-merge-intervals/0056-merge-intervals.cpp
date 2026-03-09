class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int base=intervals[0][0];
        int limit=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=limit){
                limit=max(limit,intervals[i][1]);
            }
            else{
                ans.push_back({base,limit});
                base=intervals[i][0];
                limit=intervals[i][1];
            }
        }
        ans.push_back({base,limit});
        return ans;

    }
};