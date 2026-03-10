class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        bool inserted=false;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                inserted=true;
                break;
            }
        }
        if(!inserted){
            intervals.push_back(newInterval);
        }
        int base=intervals[0][0];
        int limit=intervals[0][1];
        for(int i=1;i<n+1;i++){
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