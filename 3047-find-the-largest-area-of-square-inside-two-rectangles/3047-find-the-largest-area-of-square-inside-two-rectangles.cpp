class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bLeft, vector<vector<int>>& tRight) {
        int n=bLeft.size();
        long long max_side=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int iRight_y=min(tRight[i][1],tRight[j][1]);
                int iRight_x=min(tRight[i][0],tRight[j][0]);
                int iLeft_x=max(bLeft[i][0],bLeft[j][0]);
                int iLeft_y=max(bLeft[i][1],bLeft[j][1]);
                int w=iRight_x-iLeft_x;
                int h=iRight_y-iLeft_y;
                long long side=min(w,h);
                max_side=max(max_side,side);
            }
        }
        return max_side*max_side;
    }
};